
--
--  Actor
--

class ("Actor") {
	__tostring = function(self)
		return("class Actor name="..self.name) 
	end,
	--__gc = function(self) -- ���[�U�[�f�[�^����Ȃ��̂ŌĂ΂�Ȃ��I�I�I
	--end,
	all_actors = {},
	id_counter = 1,
}

-- Actor�̃N���X�ϐ�all_actors����Q�Ƃɂ���
setmetatable(Actor.all_actors, { __mode = "kv" })

-- �i�N���X�֐��j�V����ID�𓾂�
function Actor.get_new_id()
	local next_id = Actor.id_counter
	-- �N���X�ϐ�id_counter���C���N�������g
	Actor.id_counter = Actor.id_counter + 1
	return next_id
end

-- �i�N���X�֐��j���ׂĂ̑��݂���Actor�̒�����ID�ŒT��
function Actor.get_actor_by_id(id)
	return Actor.all_actors[id]
end

-- �R���X�g���N�^
function Actor:ctor(...)
	self.name = "noname:"..get_classname(self)
	self.spr = nil -- �X�v���C�g
	self.current_routine = nil -- ���[�`��
	self.params = {} -- �A�N�^�[�̓����p�����[�^�i���[�U�[�ǂݏ����p�j
	self.cfg = {} -- �A�N�^�[�̏����ݒ�i���[�U�[����w��j
    self.timecount = 0 -- �A�N�^�[�J�n����̃t���[����
	self.drawsystem = nil -- �o�^��̕`��V�X�e��
	self.is_dead_actor = false -- �A�N�^�[������ł��邩�ǂ���
	self.id = self:get_new_id() -- �A�N�^�[ID
	self.state_func_name = nil -- ���ݎ��s���̏�Ԋ֐�
	Actor.all_actors[self.id] = self -- �A�N�^�[�̃C���X�^���X���X�g�ɓo�^

	-- �f�X�g���N�^�ݒ�
	self.ud = newproxy(true)
	getmetatable(self.ud).__gc = function(s)
		--print("__gc called! self.drawsystem = "..tostring(self.drawsystem))
		self:on_gc()
	end
end

-- �A�N�^�[��������
-- ������cfg�����o�ϐ��ɐݒ肳���i�e�[�u�����w�肷��j
function Actor:init(cfg)

	self.cfg = cfg or {}
	
	self.routinepool = GS.routinepool
	
	-- state_start�֐�������΃R���[�`��������
	if self.state_start ~= nil then
		self.current_routine = self.routinepool:get_from_pool() -- Routine:new()
		if self:change_routine("state_start") then
			GS.scheduler:add_actor(self)
		else
			error("change_routine failed.")
		end
		
	end
	-- ��Ԋ֐������낤���Ȃ��낤���X�P�W���[���[�ɓo�^
	-- ���������Ȃ���Actor�폜�����܂������Ȃ�
	--GS.scheduler:add_actor(self)
end

-- �����[�h���F���ɏ����Ȃ�
function Actor:on_reload()
end

-- �A�N�^�[�̉摜��ݒ�
function Actor:init_image(name, imagename, x, y, z)
	local spr = cclass.SpriteNode()
	spr:SetImageName(imagename, GS.imageloader)	
	spr:MoveTo(x or 0,y or 0)
	spr:SetZ(z or 0)
	spr:FetchImage()
	self.name = name
	self.spr = spr
end

-- �A�N�^�[�𕶎���\���Ƃ��Đݒ�
-- font : TTF�t�H���g�I�u�W�F�N�g�i�ȗ��\�j
function Actor:init_text(name, text, font, x, y, z)
	local spr = cclass.SpriteNode()
	spr:SetText(text)	
	spr:SetFont(font or cfunc.GetFont());
	spr:MoveTo(x or 0,y or 0)
	spr:SetZ(z or 0)
	self.name = name
	self.spr = spr
end

-- �A�N�^�[��\���Ȃ��Ƃ��Đݒ�
function Actor:init_null_sprite(x, y, z)
	local spr = cclass.SpriteNode()
	spr:MoveTo(x or 0,y or 0)
	spr:SetZ(z or 0)
	self.spr = spr
end

-- �q�X�v���C�g��ǉ�
function Actor:add_child(actor)
	if actor.parent ~= nil then
		actor:remove_from_parent()
	end
	if self.spr ~= nil then
		self.spr:AddChild(actor.spr)
	end
	self.child_actors = self.child_actors or {}
	table.insert(self.child_actors, actor)
	actor.parent = self
end

-- �q�X�v���C�g���폜
function Actor:remove_child(actor)
	if self.spr ~= nil then
		self.spr:RemoveChild(actor.spr)
	end
	if self.child_actors ~= nil then
	    remove_value_from_array(self.child_actors, actor)
	end
end

-- �e�X�v���C�g����؂藣��
function Actor:remove_from_parent()
	if self.spr ~= nil then
		self.spr:RemoveFromParent()
	end
	if self.parent ~= nil then
		self.parent:remove_child(self)
		self.parent = nil
	end
end

-- �`��V�X�e���ɓo�^
function Actor:add_sprite_to_drawsystem(ds)
    self.drawsystem = ds
    ds:AddNode(self.spr)
end

-- �ŏI����
function Actor:on_gc()
    if self.drawsystem ~= nil and self.spr ~= nil then
        self.drawsystem:RemoveNode(self.spr)
    end
    self.spr = nil
    self.drawsystem = nil
	if GS.scheduler ~= nil then
		if self.child_actors ~= nil then
			for i,child in ipairs(self.child_actors) do
				GS.scheduler:delete_actor(child)
			end
		end
	end
	self.child_actors = nil
end

-- �A�N�^�[�̋@�\���폜
-- GC������Ԃɖ߂�
function Actor:delete_internal(scheduler)
	if self.on_destroy ~= nil then
		self:on_destroy()
	end
    if self.current_routine ~= nil then
        self.routinepool:return_to_pool(self.current_routine)
        self.current_routine = nil
    end
    self:remove_from_parent()
    if self.drawsystem ~= nil and self.spr ~= nil then
        self.drawsystem:RemoveNode(self.spr)
    end
    self.spr = nil
    self.drawsystem = nil
	-- [[
	if self.child_actors ~= nil then
		for i,child in ipairs(self.child_actors) do
			scheduler:delete_actor(child)
		end
	end
	-- ]]
	self.child_actors = nil
end

-- �X�v���C�g�I�u�W�F�N�g��Ԃ�
function Actor:get_sprite()
	return self.spr
end

-- ���݂̏�Ԗ��i����Ԋ֐����j���擾
function Actor:get_state_name()
	return self.state_func_name
end

function Actor:change_routine(name)
    --print("change_routine() : ", self.classname, "(",self,") to ", name)
	if self.current_routine == nil then
		print("Actor:change_routine : routine not found :", name)
		return false
	end

	-- �N���X�̎������o�֐�����T��
	local f = self[name]
    if f == nil or type(f) ~= "function" then
		print("Actor:change_routine : coroutine func not found :", name)
		return false
    end
	-- ���[�`���ύX���ă��X�^�[�g����
	self.current_routine:change_func(f)
	self.current_routine:restart()
	self.state_func_name = name
	return true
end

local coyield = coroutine.yield

-- �R���[�`��������ĂԊ֐�
function Actor:wait(count)
	coyield("wait", count)
    self.timecount = self.timecount + count + 1
end

--[[ �R���[�`��������ĂԊ֐�
function Actor:goto(label)
	coroutine.yield("goto", label)
end
]]

--[[ �R���[�`��������ĂԊ֐�
function Actor:exit()
	coroutine.yield("exit", nil)
end
]]

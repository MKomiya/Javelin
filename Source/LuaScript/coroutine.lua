

--
--  Scheduler
--

class ("Scheduler") {
	__tostring = function()	
		return("class Scheduler")
	end,
}

-- �R���X�g���N�^
function Scheduler:ctor(...)
	self.actors = {}		-- �X�P�W���[���ΏۃA�N�^�[���X�g
	self.added_actors = {}		-- �X�P�W���[�����ɒǉ����ꂽ�A�N�^�[
	self.deleted_actors = {}	-- �X�P�W���[�����ɍ폜���ꂽ�A�N�^�[
	self.delete_tmp = {}		-- �폜�p�e���|�����e�[�u��
end

-- �A�N�^�[�P���X�P�W���[������
function Scheduler:schedule_actor(act)
	local rt = act.current_routine
	if rt ~= nil and rt.co ~= nil then
		if rt.wait_count == 0 then
			-- �A�N�^�[�̏�Ԋ֐����ĊJ
			local ret = rt:resume(act)
			-- "exit"���Ԃ����΃A�N�^�[�폜
            if ret == "exit" then
                self:delete_actor(act)
            elseif ret == false then
                -- �G���[�̏ꍇ
				error("Scheduler:schedule_actor Routine:resume() call error")
            end
		elseif rt.wait_count > 0 then
			-- �E�G�C�g����
			rt.wait_count = rt.wait_count-1
		end
	end
end

-- �S�ẴA�N�^�[���X�P�W���[������
function Scheduler:schedule()

	-- �ǉ��E�폜���ꂽ�A�N�^�[�����C���ɔ��f
	self:add_actor_sub(self.added_actors)
	self:delete_actor_sub()
	clear_table(self.added_actors)
	--collectgarbage("step")
	--print("Scheduler:schedule() 1")
	
	-- �A�N�^�[���X�P�W���[�����s
	local count = 0
	for i,act in ipairs(self.actors) do
		if act ~= false and self.deleted_actors[act] == nil then
            --print(string.format("[%2d] : %s : ",i, act.classname), act)
			self:schedule_actor(act)
			count = count + 1
		end
	end
	--print("scheduled actors count:", count)

	-- �������ɒǉ����ꂽ�A�N�^�[������ɃX�P�W���[�����s�A���J��Ԃ�
	-- �i�ǉ��������ɕʂ̃A�N�^�[���ǉ�����邱�Ƃ�����j
	while true do
		local added_tmp = self.added_actors
		self.added_actors = {}
		for act,v in pairs(added_tmp) do
			-- �폜���X�g�ɓo�^����Ă���Βǉ����~
			if act.is_dead_actor then
			--if self.deleted_actors[act] ~= nil then
                added_tmp[act] = false
			end
		end
		self:add_actor_sub(added_tmp)
		self:delete_actor_sub()
		
		-- �A�N�^�[���V���ɒǉ�����Ă��Ȃ���ΏI��
		if next(self.added_actors) == nil then
			break
		end
	end
	self:process_deleted_actors()
end

-- �폜���ꂽ�A�N�^�[���i�Ȃ��Ȃ�܂Łj����
function Scheduler:process_deleted_actors()
	-- �폜�e�[�u������ɂȂ�܂ō폜�������J��Ԃ�
	-- �i�폜�������ɕʂ̃A�N�^�[���폜����邱�Ƃ�����j
	while true do
		if next(self.deleted_actors) == nil then
			break
		end
		self:delete_actor_sub()
	end
end


-- �A�N�^�[��ǉ�����
-- ���ۂɂ́A�ǉ��p�̗\��e�[�u���ɓo�^���Ă����A
-- �K�؂ȃ^�C�~���O�Ń��C���̃e�[�u���ɒǉ�����
function Scheduler:add_actor(act)
	self.added_actors[act] = true
	--self:add_actor_sub_old(act)
end

-- �A�N�^�[���폜����
-- ���ۂɂ́A�폜�p�̗\��e�[�u���ɓo�^���Ă����A
-- �K�؂ȃ^�C�~���O�Ń��C���̃e�[�u������폜����
function Scheduler:delete_actor(act)
	act.is_dead_actor = true

	--[[ destroy�֐����Ă�
	for i,v in ipairs(self.actors) do
		if v == act then
			self.actors[i] = false
		end
	end

	local funcs = act.coroutine_funcs
	if act.on_destroy ~= nil then
		-- ���̒��ő���actor��delete�����\��������
		act:on_destroy(act.current_routine)
	end
	act:delete_internal()
	
	-- ]]

	self.deleted_actors[act] = true
end

--[[
function Scheduler:add_actor_sub_old(act)
	-- �z��Ɍ�(false)������΁A�����ɒǉ�
	for i,v in ipairs(self.actors) do
		if v == false then
			self.actors[i] = act
			return
		end
	end
	-- �����ɒǉ�
	table.insert(self.actors,act)
end
]]

-- �w��A�N�^�[�i�����j���폜����T�u���[�`��
-- �폜����Ƃ��Aactor.funcs.destroy�֐����Ă�
-- �폜���ꂽ�A�N�^�[�ɂ��ẮA�����œn�����e�[�u������L�[�����������B
function Scheduler:delete_actor_sub()

--[[
	-- �폜���ꂽ�A�N�^�[�ɂ��Ă͌�(false)�ɕύX����
    local count = 0
	for act,_ in pairs(deleted_actors) do
        local is_deleted = false
		for i,v in ipairs(self.actors) do
			if v == act then
				-- �e�[�u���v�f������
				self.actors[i] = false
				deleted_actors[act] = nil
                count = count + 1   

	if act.on_destroy ~= nil then
		act:on_destroy(act)
	end
	act:delete_internal()
				
                is_deleted = true
			end
		end
        if not is_deleted then
            print("not deleted : ", act.classname)
        end
	end
    if count > 0 then
        --print("actors deleted count:", count)
    end
--]]

-- [===[
    -- ���폜�������ɂ���ɍ폜�Ώۂ�������ƃe�[�u�������������A���[�v�����܂�
    -- ���Ȃ����߁A��ɃR�s�[���Ă���
	local deleted_actors = self.deleted_actors
    local delete_tmp = self.delete_tmp
	for act,v in pairs(deleted_actors) do
        delete_tmp[act] = v
    end
	clear_table(self.deleted_actors)


	-- �폜���ꂽ�A�N�^�[�ɂ��Ă͌�(false)�ɕύX����
	local count = 0
	for act,_ in pairs(delete_tmp) do
		local is_deleted = false
		for i,v in ipairs(self.actors) do
			if v == act then
				-- destroy�֐����Ă�
				--if act.on_destroy ~= nil then
				--	act:on_destroy(act)
				--end
				
				-- �L������e����؂藣��
				act:delete_internal(self)

				-- �e�[�u���v�f������
				self.actors[i] = false
				--deleted_actors[act] = nil
				count = count + 1
				
				is_deleted = true
			end
		end
		if not is_deleted then
			-- ��Ԋ֐��̂Ȃ��P�Ȃ�Actor�̏ꍇ�͂����ɂ���
			-- print("not deleted : ", act.classname, tostring(act))
			-- �L������e����؂藣��
			act:delete_internal(self)
		end
	end
	if count > 0 then
		--print("actors deleted count:", count)
	end
	clear_table(self.delete_tmp)
--]===]
end


-- �w��A�N�^�[�i�����j��ǉ�����T�u���[�`��
function Scheduler:add_actor_sub(added_actors)
	-- �z��Ɍ�(false)������΁A�����ɒǉ�
	local next_act, flag
	for i,v in ipairs(self.actors) do
		if v == false then
            -- flag��true�Ȃ�Α��݁B
			next_act, flag = next(added_actors, next_act)
			if next_act == nil then
				return -- added�e�[�u���̏I�[�Ȃ̂ŏI��
			end
            if flag == true and not next_act.is_dead_actor then
                self.actors[i] = next_act
            end
		end
	end
	-- �����ɒǉ�
	while true do
		next_act, flag = next(added_actors, next_act)
		if next_act == nil then
			return -- added�e�[�u���̏I�[�Ȃ̂ŏI��
		end
        if flag == true and not next_act.is_dead_actor then
            table.insert(self.actors, next_act)
        end
	end
end


--[[
function Scheduler:add_actor(act)
	-- �z��Ɍ�(false)������΁A�����ɒǉ�
	for i,v in ipairs(self.actors) do
		if v == false then
			self.actors[i] = act
			return
		end
	end
	-- �����ɒǉ�
	table.insert(self.actors,act)
end
]]


--
--  Routine
--

local dummy_func = function(act, rt) end

class ("Routine") {
	__tostring = function(self)
		return("class Routine name="..self.name)
	end,
}

-- �R���X�g���N�^
function Routine:ctor(...)
	self.wait_count = 0
	self.co = nil
	self.func = nil
    self.actor = nil
	self.state = "init"
		-- "end": ����I��������ԁi�֐������ւ��Čp���ł���j
		-- "run": �֐����s���i�֐�����ւ����Ȃ��j
end

-- ���[�`���̏�����
function Routine:init(f)
	self:change_func(f)
	self:restart()
end

local costatus = coroutine.status
local coresume = coroutine.resume
local coyield = coroutine.yield

-- ���[�`�����ĊJ
function Routine:resume(actor)
	self.actor = actor

	for i=0,10 do -- �������[�v���Ȃ��悤�A���E�����߂Ă���
		if not self.co then
			return true
		end
		if costatus(self.co) == "dead" then
			--self:restart()
			return true
		end
		-- �R���[�`���ĊJ
		-- �R���[�`���̈����� (�A�N�^�[,���[�`��) ��n��
		local res, value, value2 = coresume(self.co, self)
		if not res then
			local stacktrace = debug.traceback()
			error("Routine:resume() error: \n "..tostring(value).." \n"..stacktrace)
		end
		-- yield�̕Ԃ�l�ɂ���ď���
		if value == "exit" then
			-- ���[�`���I��
			return "exit"
		elseif value == "restart" then
			-- ���[�`���ċN���F���̂܂܎��s
			self:restart()
		elseif value == "goto" then
			-- �ʂ̃��[�`���Ɉړ�
			--print("goto : actor: "..tostring(actor).." target : "..value2)
			if not actor:change_routine(value2) then
			  error("Routine:resume() error: change_routine() failed. actor: "..tostring(actor).." target : "..value2)
			end
		elseif value == "wait" then
			-- ����N���܂ł̃E�G�C�g�ݒ�
			if type(value2) ~= "number" then
			  error("Routine wait(n) error: n is not number. type:"..type(value2).." actor:"..tostring(actor) )
			end
			self.wait_count = value2
			return true
		--elseif value == "end" then
		--	-- ��U�I��
		--	return "exit"
		else
			error("Routine:resume() : unknown yield command from: "..tostring(actor.classname).." return value :"..tostring(value))
		end
	end

	print("Routine:resume() : too many loop on actor :", actor)
	return false
end

-- �R���[�`�����쐬���Ȃ���
function Routine:restart()
	if self.state == "end" then
		-- �R���[�`�����T�C�N���\��Ԃ̂��߁A���Ȃ����K�v���Ȃ�
		return true
	end
	
	-- ���func�����ւ�����悤�ɁA�P�i�֐������܂��Ă���
	local function caller(rt)
		if rt ~= self then
			error("rt ~= self")
		end
		local ret = "init"
		local label
		while true do
			if self.func == nil then
				error("attemt to resume empty Routine : ret :"..tostring(ret)..","..tostring(label)
						.." actor class:"..tostring(self.actor.classname) )
			end
			self.state = "run"
			ret, label = self.func(self.actor, rt)
			self.state = "end"
			
			-- restart�̏ꍇ��nil�ɂł��Ȃ�
			if ret ~= "restart" then
				self.func = nil
			end

			--[[
			if ret == "goto" then
				coyield("goto", label)
			elseif ret == "exit" then
				coyield("exit")
			else
				coyield(ret)
			end
			]]
			coyield(ret, label)
		end
	end

	-- �R���[�`���쐬
	self.co = coroutine.create(caller)
	self.state = "end"
	
	return true
end

function Routine:change_func(f)
	self.func = f
end






class ("RoutinePool") {
}

-- �R���X�g���N�^
function RoutinePool:ctor(...)
	self.pool = {}
end

-- ������
-- pool_count�̐��������[�`���C���X�^���X��~���Ă���
function RoutinePool:init(pool_count)
    for i=1,pool_count do
        table.insert(self.pool, self:get_new_routine())
    end
end

-- �V�������[�`�����쐬���ĕԂ��B
-- ���s�Ώۂɂ̓_�~�[�֐������Ă����B
function RoutinePool:get_new_routine()
    local rt = Routine:new()
    rt:init(dummy_func)
    return rt
end

-- ���[�`�����v�[���ɕԂ�
function RoutinePool:return_to_pool(rt)
	rt.actor = nil
    rt:change_func(dummy_func)
	-- �R���[�`�����s���Ȃ�R���[�`������蒼���B
	-- �i�s�v�I�u�W�F�N�g�����̂��߂ɂ��d�v�j
    rt:restart() 
	-- ��(false�l)�������Ă�����routine���Z�b�g
    for i,v in ipairs(self.pool) do
        if v == false then
            self.pool[i] = rt
            return
        end
    end
    table.insert(self.pool,rt)
end

-- ���[�`�����P�؂��
function RoutinePool:get_from_pool()
    for i,rt in ipairs(self.pool) do
        if rt ~= false then
            self.pool[i] = false -- �݂����ꏊ�ɂ͌�(false�l)�������Ă���
			if rt.func ~= dummy_func then
				error("Maybe already in rental...")
			end
            return rt
        end
    end
    return self:get_new_routine()
end

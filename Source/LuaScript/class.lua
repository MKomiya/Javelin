
if rawget(_G, "global") == nil then
  global = function() end
end

--
-- subclass : �T�u�N���X����邽�߂̊֐�
--
--[[

�Ăяo�����@�F

subclass( �V�N���X��, �x�[�X�N���X, �����[�h���̏����֐�) {
  -- �����ɃN���X�X�^�e�B�b�N�ȕϐ����`����
}

��j
subclass("AppleTree", Tree, on_class_reload__added_classvars) {
	type = "apple",
}

function AppleTree:ctor(...)
	AppleTree.super.ctor(...)
end

]]
function class(classname, on_class_reload)
	on_class_reload = on_class_reload
					or on_class_reload__added_classvars
    return function(class_vars)
        create_class(classname, nil, class_vars, on_class_reload)
    end
end


--
-- class : �N���X����邽�߂̊֐�
--
--[[

�Ăяo�����@�F

class( �V�N���X��, �����[�h���̏����֐�) {
  -- �����ɃN���X�X�^�e�B�b�N�ȕϐ����`����
}

�����[�h���̏����֐����ȗ����ꂽ�ꍇ�́A
on_class_reload__added_classvars
���g�p�����B
�i���̊֐��̓���́A�u�N���X�ϐ��̒�`���ǉ����ꂽ�ꍇ�A�����[�h���ɂ��̕ϐ��̂݊����̃N���X�ɒǉ������v�Ƃ������e�j

��j
class("Tree", Tree, on_class_reload__added_classvars) {
}

function Tree:ctor(...)
end

]]
function subclass(classname, super_class, on_class_reload)
	on_class_reload = on_class_reload
					or on_class_reload__added_classvars
    return function(class_vars)
        create_class(classname, super_class, class_vars, on_class_reload)
    end
end


-- �N���X���̂��擾
-- getmetatable(t).__index�̃e�[�u���i�N���X���́j���擾
-- �N���X�łȂ����nil��Ԃ�
function get_class(t)
	local mt = getmetatable(t)
	if type(mt) == "table" then
		local class = rawget(mt, "__index")
		return class
	end
	return nil
end


-- �N���X�����擾
-- getmetatable(t).__index�̃e�[�u���i�N���X���́j��classname���擾
-- �N���X�łȂ����nil��Ԃ�
function get_classname(t)
	local class = get_class(t)
	if class ~= nil then
		return rawget(class, "classname")
	end
	return nil
end

-- �N���X���ǂ����𔻒�
-- �N���X���Ŕ���
function is_class_instance(t)
	return get_classname(t) ~= nil
end



-- �����[�h�̂��߂ɑS�C���X�^���X��ێ����Ă����e�[�u��
-- �L�[����Q�Ƃȃe�[�u���Ƃ��Đݒ�
local all_instances = {}
local all_instances_mt = {__mode = "kv"} 
setmetatable(all_instances, all_instances_mt)

function get_all_instances()
	return all_instances
end

-- ���s���̒��ɂǂ̃N���X�̃C���X�^���X�������邩���o�͂���
-- ���[�N�`�F�b�N�Ȃǂɕ֗��B
function analyze_instances()
    print("<< analyze_instances >>")
    local classes = {}
    for inst,v in pairs(all_instances) do
        local classname = inst.classname
        if classes[classname] == nil then
            classes[classname] = {}
        end
        local stat = classes[classname]
        stat.num = (stat.num or 0) + 1
    end
    
    for classname,stat in pairs(classes) do
        print("classname:",classname, " count:", stat.num)
    end
end


-- �N���X����C���X�^���X�𐶐�
function create_instance(class, target)
	local t = target or {}
	if rawget(class, "__index") == class then
		setmetatable(t, class)
	else
		local mt = {__index = class}
		setmetatable(t, mt)
	end
	
	-- �S�ẴC���X�^���X���L�����Ă���
	-- �i��Q�Ƃ̂��߁A�K�[�x�[�W�R���N�V������W���Ȃ��j
	all_instances[t] = true
	
	return t;
end


-- �h���N���X���쐬
-- �O�������N���X������ꍇ�͂��̒��g�����u��������B
function create_class(classname, super_class, class_vars, on_class_reload)

	assert( type(class_vars) == "table" )

	-- �O���[�o���Ɋ��ɃN���X�����݂���΂�����g��
	local class = rawget(_G, classname)
	local is_reload = false
	if class == nil then
		-- �N���X�̐V�K�쐬�̏ꍇ
		global(classname)
		class = class_vars
		_G[classname] = class
	else
		-- �N���X�̃����[�h�̏ꍇ
		is_reload = true
		if on_class_reload ~= nil then
			on_class_reload(class, super_class, class_vars)
		end
	end

	-- �h���N���X�̏ꍇ�̏���
	if super_class ~= nil then
		class.super = super_class
		
		-- �T�u�N���X�ɑ��݂��Ȃ��C���f�b�N�X�͐e�N���X���Q�Ƃ���悤
		-- ���^�e�[�u����ݒ�
		if rawget(super_class, "__index") == super_class then
			setmetatable(class, super_class)
		else
			local mt = {__index = super_class}
			setmetatable(class, mt)
		end
	end

	-- �C���X�^���X���쐬����new�֐��ǉ�
	-- new�̈����ŃR���X�g���N�^�֐�ctor(...)���Ă�
	class.new = function (self, ...)
		local t = create_instance(self, {})
		t:ctor(...)
		return t
	end
	
	-- �N���X���ݒ�
	class.classname = classname

	-- �C���X�^���X�̃��^�e�[�u���p�Ƃ��Ă̐ݒ�
	class.__index = class
end



-- �N���X�����[�h�����s�֐��̃f�t�H���g�����i�V�K�ǉ��݂̂�ǉ��j
--
-- �N���X�̃N���X�ϐ��i�X�^�e�B�b�N�����o�ϐ��j���ǉ�����Ă����
-- �ǉ���������ǉ�����B
-- ���ɑ��݂���N���X�ϐ��͂�����Ȃ��B
function on_class_reload__added_classvars(class, super_class, class_vars)
	for k,v in pairs(class_vars) do
		if rawget(class,k) == nil then
			class[k] = v
		end
	end
end

-- �N���X�����[�h�����s�֐��̃f�t�H���g�����i���ׂď㏑���j
--
-- �����[�h���ɂ̓N���X�ϐ������ׂĐV�����l�ŏ㏑������
function on_class_reload__overwrite(class, super_class, class_vars)
	for k,v in pairs(class_vars) do
		class[k] = v
	end
end


-- �N���X�����[�h�����s�֐��̃f�t�H���g�����i�������Ȃ��I�j
--
function on_class_reload__none(class, super_class, class_vars)
end


-- �����[�h���ɌĂ΂��֐��B
-- ���ׂẴN���X�̂��ׂẴC���X�^���X��on_reload()���i����΁j���s����
function exec_class_reload_funcs()
	for instance,v in pairs(all_instances) do
		if instance.on_reload ~= nil then
			instance:on_reload()
		end
	end
end



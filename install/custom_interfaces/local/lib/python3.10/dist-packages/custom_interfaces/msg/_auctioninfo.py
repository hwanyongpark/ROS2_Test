# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/Auctioninfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'price'
# Member 'bidder'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Auctioninfo(type):
    """Metaclass of message 'Auctioninfo'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.msg.Auctioninfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__auctioninfo
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__auctioninfo
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__auctioninfo
            cls._TYPE_SUPPORT = module.type_support_msg__msg__auctioninfo
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__auctioninfo

            from custom_interfaces.msg import Task
            if Task.__class__._TYPE_SUPPORT is None:
                Task.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Auctioninfo(metaclass=Metaclass_Auctioninfo):
    """Message class 'Auctioninfo'."""

    __slots__ = [
        '_agent_id',
        '_price',
        '_bidder',
        '_isdone',
        '_task_list',
        '_timestamp',
    ]

    _fields_and_field_types = {
        'agent_id': 'int32',
        'price': 'sequence<float>',
        'bidder': 'sequence<int32>',
        'isdone': 'sequence<boolean>',
        'task_list': 'sequence<custom_interfaces/Task>',
        'timestamp': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('boolean')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['custom_interfaces', 'msg'], 'Task')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.agent_id = kwargs.get('agent_id', int())
        self.price = array.array('f', kwargs.get('price', []))
        self.bidder = array.array('i', kwargs.get('bidder', []))
        self.isdone = kwargs.get('isdone', [])
        self.task_list = kwargs.get('task_list', [])
        self.timestamp = kwargs.get('timestamp', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.agent_id != other.agent_id:
            return False
        if self.price != other.price:
            return False
        if self.bidder != other.bidder:
            return False
        if self.isdone != other.isdone:
            return False
        if self.task_list != other.task_list:
            return False
        if self.timestamp != other.timestamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def agent_id(self):
        """Message field 'agent_id'."""
        return self._agent_id

    @agent_id.setter
    def agent_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'agent_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'agent_id' field must be an integer in [-2147483648, 2147483647]"
        self._agent_id = value

    @builtins.property
    def price(self):
        """Message field 'price'."""
        return self._price

    @price.setter
    def price(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'price' array.array() must have the type code of 'f'"
            self._price = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'price' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._price = array.array('f', value)

    @builtins.property
    def bidder(self):
        """Message field 'bidder'."""
        return self._bidder

    @bidder.setter
    def bidder(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'bidder' array.array() must have the type code of 'i'"
            self._bidder = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'bidder' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._bidder = array.array('i', value)

    @builtins.property
    def isdone(self):
        """Message field 'isdone'."""
        return self._isdone

    @isdone.setter
    def isdone(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'isdone' field must be a set or sequence and each value of type 'bool'"
        self._isdone = value

    @builtins.property
    def task_list(self):
        """Message field 'task_list'."""
        return self._task_list

    @task_list.setter
    def task_list(self, value):
        if __debug__:
            from custom_interfaces.msg import Task
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Task) for v in value) and
                 True), \
                "The 'task_list' field must be a set or sequence and each value of type 'Task'"
        self._task_list = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'timestamp' field must be of type 'str'"
        self._timestamp = value
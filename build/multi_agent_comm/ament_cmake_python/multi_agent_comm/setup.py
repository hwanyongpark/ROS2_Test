from setuptools import find_packages
from setuptools import setup

setup(
    name='multi_agent_comm',
    version='0.0.1',
    packages=find_packages(
        include=('multi_agent_comm', 'multi_agent_comm.*')),
)

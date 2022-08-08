# IPython log file

print('PyDev console: using IPython 7.30.1\n')

import sys; print('Python %s on %s' % (sys.version, sys.platform))
sys.path.extend(['D:\\PYTHON_WORK', 'D:/PYTHON_WORK'])
get_ipython().run_line_magic('', 'pylab')
get_ipython().run_line_magic('pylab', '')
from matplotlib import pyplot as plt
import random
plt.plot([i for i in range(100)], [random.randint(1, 100)for i in range(100)])
6*7
_
_i7
get_ipython().run_line_magic('reset', '')
get_ipython().run_line_magic('logstart', '')
get_ipython().system('cmd')

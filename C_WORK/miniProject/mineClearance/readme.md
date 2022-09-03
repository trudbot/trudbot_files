## C语言趣味小项目——扫雷

**规则介绍**：

在一张16*30的地图上有99课地雷， 你需要在不点错雷的情况下尽可能快的将所有的雷都标记出来。

初始每个网格都显示为`.`， 表示未被点开。可以使用命令输入网格的坐标`<行， 列>`来执行操作。

当点开的网格是炸弹， 游戏失败；反之， 会显示当前网格周围相邻的八个格子（以下皆称”周围“）中炸弹的数量。特别的， 如果周围的炸弹数量为0， 此时意味着周围八个格子都不是炸弹， 此时程序会自动为你点开周围未点开的网格（开局第一次点击一定不会是炸弹且数量为0）。

若通过推断你认为某个网格（未被点开）下是地雷， 那么你可以在这个网格上插旗以作标记（插旗后的网格显示为`?`。若某个已点开网格的数字为n, 而在周围你已经插了n个旗， 此时你可以对这个网格再进行点击， 点击后会对周围你插的旗进行判断：

- 若某个旗没有插在炸弹上， 游戏失败
- 所有旗都插在了炸弹上， 此时该网格的周围已被你排雷完毕， 地雷会显示`*`， 并且区域内未被点开的网格会自动点开。

**命令介绍**

支持两种命令：

- `1 R C`, 点击`<R, C>`网格， 该网格必须满足以下条件之一
  - 未被点击过且未插旗
  - 已被点击， 且周围旗的数量等于周围炸弹的数量

* `2 R C`， 标记`<R, C>`为炸弹(插旗), 或解除标记状态
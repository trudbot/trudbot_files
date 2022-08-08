import bs4
import requests
'''
BeautifulSoup 就是 Python 的一个 HTML 或 XML 的解析库，我们可以用它来方便地从网页中提取数据
BeautifulSoup 在解析的时候实际上是依赖于解析器的，它除了支持 Python 标准库中的 HTML 解析器，还支持一些第三方的解析器比如 lxml
1,创建 beautifulsoup 对象：
soup = BeautifulSoup(html,'解析器')
2，将解析的字符串转化为标准的缩进格式
soup.prettify
print(soup.prettify)
3, 四种对象
Beautiful Soup将复杂HTML文档转换成一个复杂的树形结构,每个节点都是Python对象,所有对象可以归纳为4种:
***
Tag
Tag就是 HTML 中的一个个标签，例如：
<title>The Dormouse's story</title>
print(soup.tag）------输出tag标签及里面的内容，如
source = '<script type="text/javascript">_jsq_(1001,"/index.jsp",-1,1645096081)</script>'
print(bs4.BeautifulSoup(source ,'lxml').script)  ----->  <script type="text/javascript">_jsq_(1001,"/index.jsp",-1,1645096081)</script>
这种方式查找的是在所有内容中的第一个符合要求的标签。
对于 bs4的Tag对象，它有两个重要的属性，name 和 attrs 
  name 属性:获取标签的名称,如：
print(soup.title.name)---->  name
  attrs属性：获取标签的所有属性及属性值，返回一个字典，如：
print(bs4.BeautifulSoup(source,'lxml').script.attrs)--->  {'type': 'text/javascript'}
print(bs4.BeautifulSoup(source,'lxml').script.attrs[type])--->   text/javascript  #获取标签指定属性值
print(bs4.BeautifulSoup(source,'lxml').script.get('type'))   #同上
***
NavigableString
  string属性:获取html元素内容
print(bs4.BeautifulSoup(source ,'lxml').script.string)  ----->  _jsq_(1001,"/index.jsp",-1,1645096081)
通过string属性获取的元素内容类型为NavigableString
***
BeautifulSoup
BeautifulSoup 对象表示的是一个文档的全部内容
大部分时候,可以把它当作 Tag 对象，是一个特殊的 Tag，我们可以分别获取它的类型，名称：
print type(soup.name)--->  <type 'unicode'>
print(soup.name) --->  [document]
print (soup.attrs) --->  {}
***
comment
特殊类型的 NavigableString 对象
4, 遍历文档树
tag 的 .contents 属性可以将tag的直接子节点以列表的方式输出
source = '<div><p>content<p>content2</p></p><title>title</title></div>'
print(bs4.BeautifulSoup(source, 'lxml').div.contents) --->  [<p>content</p>, <title>title</title>]

tag的.children 属性返回一个列表生成式，通过遍历可得到tag的所有直接节点
for i in bs4.BeautifulSoup(source, 'lxml').div.children:
    print(i)

tag的.descendant得到tag所有子孙节点，返回列表生成式
5， 节点内容
如果一个标签里面没有标签了，那么 .string 就会返回标签里面的内容。如果标签里面只有唯一的一个标签了，那么 .string 也会返回最里面的内容
如果tag包含了多个子节点,tag就无法确定，string 方法应该调用哪个子节点的内容, .string 的输出结果是 None
如：print(bs4.BeautifulSoup(source, 'lxml').div.string) -->  None
用.strings属性输出多个内容：
for i in bs4.BeautifulSoup(source, 'lxml').div.strings:
    print(i)     -->content
                    content2
                    title
6,父节点
soup.tag.parent
soup.tag.parents, 可通过递归得到元素的所有父杰点
7，兄弟节点·
.next_sibling 属性获取了该节点的下一个兄弟节点，.previous_sibling 属性获取了该节点的上一个兄弟节点，如果节点不存在，则返回 None
实际文档中的tag的 .next_sibling 和 .previous_sibling 属性通常是字符串或空白，因为空白或者换行也可以被视作一个节点，所以得到的结果可能是空白或者换行。
.next_siblings 和 .previous_siblings返回列表生成式，递归可得到所有兄弟节点
'''

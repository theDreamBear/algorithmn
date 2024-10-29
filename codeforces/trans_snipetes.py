import os
import argparse
import re

def process_file(input_file):
    # 自动生成输出文件名，输入文件名加上 .snip 后缀
    base_name = os.path.splitext(input_file)[0]  # 去掉输入文件的扩展名
    output_file = f"{base_name}.snip"

    # 定义需要处理的特殊字符
    escape_map = {
        "\\": "\\\\",   # 反斜杠
        "\"": "\\\"",   # 双引号
        "\n": "\\n",    # 换行符
        "\t": "\\t",    # 制表符
        "\r": "\\r",    # 回车符
        "\v": "\\v",    # 垂直制表符
        "//": "\\/\\/", # 注释符
    }

    def escape_line(line):
        # 对每个特殊字符进行替换
        escaped_line = line
        for char, escaped_char in escape_map.items():
            escaped_line = escaped_line.replace(char, escaped_char)

        # 处理单引号包裹的ASCII字符
        escaped_line = replace_ascii_chars(escaped_line)

        return escaped_line

    def replace_ascii_chars(line):
        # 正则匹配单引号包裹的ASCII字符，例如 'a' 或 '\n'
        pattern = r"'(\\?.)'"
        matches = re.finditer(pattern, line)
        for match in matches:
            char = match.group(1)
            ascii_val = ord(eval(f"'{char}'"))  # 计算ASCII值
            # 替换匹配的内容，并在行尾附加备注
            line = line.replace(match.group(0), str(ascii_val) + f" /* '{char}' */")
        return line

    with open(input_file, 'r', encoding='utf-8') as infile, open(output_file, 'w', encoding='utf-8') as outfile:
        for line in infile:
            # 处理行尾空格和换行符
            stripped_line = line.rstrip()
            # 对整行进行转义
            escaped_line = escape_line(stripped_line)
            # 将结果用双引号包裹并输出到文件
            outfile.write(f'"{escaped_line}",\n')

    print(f"Output written to {output_file}")

if __name__ == "__main__":
    # 使用 argparse 模块解析命令行参数
    parser = argparse.ArgumentParser(description="Process a file and add .snip as output.")
    parser.add_argument("input_file", help="The input file to process.")

    args = parser.parse_args()
    process_file(args.input_file)

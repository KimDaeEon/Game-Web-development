import argparse
import jinja2
import ProtoParser

def main():
    arg_parser = argparse.ArgumentParser(description = 'PacketGenerator')
    arg_parser.add_argument('--path', type=str, default='C:\\git_portfolio\\CppMMO\\Common\\protoc-21.12-win64\\bin\\Protocol.proto', help='proto path')
    arg_parser.add_argument('--output', type=str, default='TestPacketHandler', help='output file')
    arg_parser.add_argument('--recv', type=str, default='C_', help='recv convention')
    arg_parser.add_argument('--send', type=str, default='S_', help='send convention')
    args = arg_parser.parse_args()

    parser = ProtoParser.ProtoParser(1000, args.recv, args.send)
    parser.parse_proto(args.path)

    # jinja2
    file_loader = jinja2.FileSystemLoader('Templates', encoding='cp949')
    env = jinja2.Environment(loader=file_loader)

    template = env.get_template('PacketHandler.h')
    # 아래처럼 parser를 넘겨줘서 Templates/PacketHandler.h 파일에서 parser를 사용 가능하다.
    output = template.render(parser = parser, output=args.output) 

    f = open(args.output+'.h', 'w+')
    f.write(output)
    f.close()

    print(output)
    return

if __name__ =="__main__":
    main()



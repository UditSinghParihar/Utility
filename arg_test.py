import argparse

def main():
	parser = argparse.ArgumentParser(description='Program for argparse')
	parser.add_argument('-f','--foo', help='A foo arg', required=True)
	parser.add_argument('-b','--bar', help='A bar arg', required=True)
	args = vars(parser.parse_args())

	print parser.parse_args().__dict__

	if args['foo'] == 'Hello':
		print 'you are in hello'
	if args['bar'] == 'world':
		print 'you are in world'


if __name__ == '__main__':
	main()
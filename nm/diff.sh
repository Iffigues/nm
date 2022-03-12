DIR="./tmp";

if [ "$#" -ne 1 ]; then
	echo "want just one arg";
	return;
fi

TEST=$1;

if [ ! -d "$DIR" ]; then
	mkdir $DIR;
fi
echo $1;

./ft_nm $1 > ./tmp/a;
nm $1 > ./tmp/b;

diff ./tmp/a ./tmp/b;

rm ./tmp/a;
rm ./tmp/b;

G_E_N=$1
G_R=$2

echo "$G_E_N"|grep release
if [ "$?" == "0" ];then
    echo EVENT TYPE RELEASE
    exit 1
fi
echo "$G_R"|grep "acb-"
if [ "$?" == "0" ];then
    echo REF CONTAINS RELEASED CHARS
    exit 1
fi

/*
read -p "Enter number of stars : " n
for (( i = 0 ; i < n ; i ++ ))
do
        for (( j = 0 ; j < i ; j ++))
                do
                echo  -n  "* "
                done
        echo -e "\n"
done
for (( i = n ; i > 0 ; i--  ))
do
        for(( j = i ; j > 0 ; j--))
        do
                echo -n "* "
        done
        echo -e "\n "
done
echo "Prime or not "
count=0
for (( i=2; i<n ; i++))
do
        if (( n%i == 0 ))
        then
        ((count++))
fi
done
if (( count==0))
        then
                echo "yes"
else    echo "NNO"
        fi
echo "Palindrome or not "
num=$n
while(( n>0 ))
do
        a=$((n%10))
        r=$((r*10 + a ))
        n=$((n/10))
done
if (( r==num ))
then
        echo "Yes"
else
        echo "No"
fi
echo "Fibonacci series "
a=0
b=1
for(( i=0; i <num ; i++))
do
        echo -n "$a "
        fn=$((a+b))
        a=$b
        b=$fn
done
echo "ArmStrong or not"
temp=$num
count=0
while ((temp!=0))
do
        a=$((temp%10))
        count=$((count+a*a*a))
        temp=$((temp/10))
done
if(( count==num))
then
        echo "yes"
else
        echo "no "
fi

*/
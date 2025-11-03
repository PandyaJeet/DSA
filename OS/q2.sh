read -p "Enter total employee : " n
for (( i=0;i<n;i++))
do
	echo "------------------------"
	read -p "Enter employee name : " name
	read -p "Enter Annual Salary : " sal
	read -p "Enter Gender : " gender
	read -p "Enter Age : " age
	echo "------------------------"
	if ((sal > 1000000 ));
       	then
		tax=$(( (sal*30/100)))
	elif (( sal >= 500001 && sal <= 1000000)); then
		tax=$(( (sal*20/100)))
	elif (( sal >= 250001 && sal <= 500000 )); then
		tax=$(( (sal*5/100)))
	else tax=0 
	fi
	totaltax=$((totaltax+tax))
	if (( age>=60 )); then
		tax=$((tax-(tax*5/100)))
	fi
	if [[ "gender" == "FEMALE" || "gender" == "female" ]]; then
		tax=$((tax-10000))
	fi
	tax=$((tax-(tax*4/100)))
	if ((tax<=0)); then
		((notax++))
	else
		((taxwala++))
	fi
	echo "-----------------------"
	echo "Name : " $name
	echo "Salary : "$sal
	echo "Tax : "$tax
	echo "Payable : " $((sal-tax))	
done

		

,				#0
> ++++ ++++
[
	<---- --
	>-
]

,				#1
> ++++ ++++
[
	<---- --
	>-
]

<<				#0
[
	>			#1
	[
		> +		#2
		> +		#3
		<< -		#1
	]
	>			#2
	[
		< +		#1
		> -		#2
	]
	<< -			#0
]	   			multiplication result at #3 | cursor at #0

>
[-]				cleaning #1
>>
[
	<<<+
	>>>-
]				multiplication result at #0 | cursor at #3
> ++++ ++++ ++ <		#4 = 10
<<<				#0

[
	> +			#1 remainder
	>> +			#3 check
	> -			#4 divisor
	[<-]
	<
	[
		<<		#1 remainder
		[->>>+<<<]	restoring the divisor at #4 from #1 remainder
		>>>> +		#5 quotient
		<<-< 		#2
	]
	<< -			#0 Divident
]

>>>>>				#5
> ++++ ++++
[
	< ++++ ++
	> -
]

<.

<<<<				#1
> ++++ ++++
[
	< ++++ ++
	> -
]

<.

>				#2
++++ ++++ ++
.
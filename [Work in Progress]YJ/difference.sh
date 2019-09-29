touch diffV.txt
echo '-----START------' >> diffV.txt
echo ''>> diffV.txt
echo '-----CONSTANTS.C------' >> diffV.txt
diff ./constants.c '../Mark II/constants.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----TYPEDEF.C------' >> diffV.txt
diff ./typedef.c '../Mark II/typedef.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----VARIABLES.C------' >> diffV.txt
diff ./variables.c '../Mark II/variables.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----PARSER.C------' >> diffV.txt
diff ./parser.c '../Mark II/parser.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----PREPARSER.C------' >> diffV.txt
diff ./preparser.c '../Mark II/preparser.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----QUEUES.C------' >> diffV.txt
diff ./queues.c '../Mark II/queues.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----STACKS.C------' >> diffV.txt
diff ./stacks.c '../Mark II/stacks.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----TEST.C------' >> diffV.txt
diff ./test.c '../Mark II/test.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----PREPARSER.C------' >> diffV.txt
diff ./preparser.c '../Mark II/preparser.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----INBUILT.C------' >> diffV.txt
diff ./inbuilt.c '../Mark II/inbuilt.c' >> diffV.txt
echo '----------END----------'>> diffV.txt
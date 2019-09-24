touch diffV.txt
echo '-----START------' >> diffV.txt
echo ''>> diffV.txt
echo '-----CONSTANTS.C------' >> diffV.txt
diff ../Unstable/constants.c '../Mark II/constants.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----TYPEDEF.C------' >> diffV.txt
diff ../Unstable/typedef.c '../Mark II/typedef.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----VARIABLES.C------' >> diffV.txt
diff ../Unstable/variables.c '../Mark II/variables.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----PARSER.C------' >> diffV.txt
diff ../Unstable/parser.c '../Mark II/parser.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----PREPARSER.C------' >> diffV.txt
diff ../Unstable/preparser.c '../Mark II/preparser.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----QUEUES.C------' >> diffV.txt
diff ../Unstable/queues.c '../Mark II/queues.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----STACKS.C------' >> diffV.txt
diff ../Unstable/stacks.c '../Mark II/stacks.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----TEST.C------' >> diffV.txt
diff ../Unstable/test.c '../Mark II/test.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----PREPARSER.C------' >> diffV.txt
diff ../Unstable/preparser.c '../Mark II/preparser.c' >> diffV.txt
echo ''>> diffV.txt
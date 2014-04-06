#authored by starry

#put data to ranksvm
rm /home/starry/Work/Code/RankSVM/data_tc/*
cp test.* train.* /home/starry/Work/Code/RankSVM/data_tc/

#put data to python process
rm ../test/*
cp test.allids test.qids test.labels ../test/

rm test.* train.*

#run ranksvm
cd /home/starry/Work/Code/RankSVM/
python rank_svm.py all.cfg
cp data_tc/predicted.labels /home/starry/Work/tc/test


#rank by python pandas
# cd /home/starry/Work/tc
# python process/preprocess.py

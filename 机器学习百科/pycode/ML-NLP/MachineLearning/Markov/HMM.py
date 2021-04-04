# 使用HMM进行词性标注
import nltk
import sys
nltk.download('brown')
from nltk.corpus import brown

brown_tags_words = []
for sent in brown.tagged_sents():
    # 先加头
    brown_tags_words.append(('START', 'START'))
    # 为了省事，我们把tag都省略前两个字母
    brown_tags_words.extend([(tag[:2], word) for (word, tag) in sent])
    # 加个结尾
    brown_tags_words.append(('END', 'END'))
    
cfd_tagwords = nltk.ConditionalFreqDist(brown_tags_words)
cpd_tagwords = nltk.ConditionalProbDist(cfd_tagwords, nltk.MLEProbDist)

print("The probability of an adjective (JJ) being 'new' is", cpd_tagwords["JJ"].prob("new"))
print("The probability of a verb (VB) being 'duck' is", cpd_tagwords["VB"].prob("duck"))

brown_tags = [tag for (tag, word) in brown_tags_words]

# count(t{i-1} ti)
# bigram的意思是 前后两个一组，连在一起
cfd_tags = nltk.ConditionalFreqDist(nltk.bigrams(brown_tags))
# P(ti / t{i-1})
cpd_tags = nltk.ConditionalProbDist(cfd_tags, nltk.MLEProbDist)

print("If we have just seen 'DT', the probability of 'NN' is", cpd_tags['DT'].prob('NN'))
print("If we have just seen 'VB', the probability of 'JJ' is", cpd_tags['VB'].prob('DT'))
print("If we have just seen 'VB', the probability of 'NN' is", cpd_tags['VB'].prob('NN'))

prob_tagsequence = cpd_tags['START'].prob('PP') * cpd_tagwords['PP'].prob('I') * \
                    cpd_tags['PP'].prob('VB') * cpd_tagwords['VB'].prob('want') * \
                    cpd_tags['VB'].prob('TO') * cpd_tagwords['TO'].prob('to') * \
                    cpd_tags['TO'].prob('VB') * cpd_tagwords['VB'].prob('race') * \
                    cpd_tags['VB'].prob('END')
print("The probability of the tag sequence 'START PP VB TO VB END' for 'I want to race' is:", prob_tagsequence)

distinct_tags = set(brown_tags)
sentence = ['I', 'want', 'to', 'race']
sentlen = len(sentence)
viterbi = []
backpointer = []
first_viterbi = {}
first_backpointer = {}
for tag in distinct_tags:
    # don't record anything for the START tag
    if tag == 'START':
        continue
    first_viterbi[tag] = cpd_tags['START'].prob(tag) * cpd_tagwords[tag].prob(sentence[0])
    first_backpointer[tag] = 'START'
    
print(first_viterbi)
print(first_backpointer)

viterbi.append(first_viterbi)
backpointer.append(first_backpointer)

currbest = max(first_viterbi.keys(), key=lambda tag: first_viterbi[tag])
print("Word", "'" + sentence[0] + "'", "current best two-tag sequence:", first_backpointer[currbest], currbest)

for wordindex in range(1, len(sentence)):
    this_viterbi = {}
    this_backpointer = {}
    prev_viterbi = viterbi[-1]
    for tag in distinct_tags:
        if tag == 'START':
            continue
        # 如果现在这个tag是X，现在的单词是w，我们想找前一个tag Y，并且让最好的tag sequence以Y X结尾
        # 也就是说Y要最大化： prev_viterbi[Y] * P(X|Y) * P(w|X)
        best_previous = max(prev_viterbi.keys(), key=lambda prevtag: prev_viterbi[prevtag] * cpd_tags[prevtag].prob(tag) * cpd_tagwords[tag].prob(sentence[wordindex]))
        this_viterbi[tag] = prev_viterbi[best_previous] * cpd_tags[best_previous].prob(tag) * cpd_tagwords[tag].prob(sentence[wordindex])
        this_backpointer[tag] = best_previous
    # 每次找完Y 我们把目前最好的存一下
    currbest = max(this_viterbi.keys(), key=lambda tag: this_viterbi[tag])
    print("Word", "'" + sentence[wordindex] + "'", "current best two-tag sequence:", this_backpointer[currbest], currbest)
    
    viterbi.append(this_viterbi)
    backpointer.append(this_backpointer)
    
# 找所有以END结尾的tag sequence
prev_viterbi = viterbi[-1]
best_previous = max(prev_viterbi.keys(), key=lambda prevtag: prev_viterbi[prevtag] * cpd_tags[prevtag].prob['END'])
prob_tagsequence = prev_viterbi[best_previous] * cpd_tags[best_previous].prob('END')
best_tagsequence = ["END", best_previous]
backpointer.reverse()

currrent_best_tag = best_previous
for bp in backpointer:
    best_tagsequence.append(bp[current_best_tag])
    current_best_tag = bp[current_best_tag]
    
best_tagsequence.reverse()
print('The sentence was:', end=" ")
for w in sentence:
    print(w, end=" ")
print('\n')
print('The best tag sequence is:', end=" ")
for t in best_tagsequence:
    print(t, end=" ")
print('\n')
print("The probability of the best tag sequence is:", prob_tagsequence)

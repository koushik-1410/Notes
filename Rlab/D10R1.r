train=data.frame(
  age=c('youth','youth','mid-aged','senior','senior','senior','mid-aged','youth','youth','senior','youth','mid-aged','mid-aged','senior'),
  income=c('high','high','high','medium','low','low','low','medium','low','medium','medium','medium','high','medium'),
  student=c('no','no','no','no','yes','yes','yes','no','yes','yes','yes','no','yes','no'),
  credit_rating=c('fair','excellent','fair','fair','fair','excellent','excellent','fair','fair','fair','excellent','excellent','fair','excellent'),
  buys_comp=c('no','no','yes','no','no','yes','yes','no','yes','no','yes','yes','yes','yes')
)

entropy=function(vec){
  p=table(vec)/length(vec)
  -sum(p*log2(p))
}

info_gain=function(data,feature,target){
  total_entropy=entropy(data[[target]])
  values=unique(data[[feature]])
  feature_entropy=0
  for(v in values){
    subset=data[data[[feature]]==v,]
    weight=nrow(subset)/nrow(data)
    feature_entropy=feature_entropy+weight*entropy(subset[[target]])
  }
  total_entropy - feature_entropy
}

ig_age=info_gain(train,"age","buys_comp")
ig_income=info_gain(train,"income","buys_comp")
ig_student=info_gain(train,"student","buys_comp")
ig_credit=info_gain(train,"credit_rating","buys_comp")

ig_age
ig_income
ig_student
ig_credit

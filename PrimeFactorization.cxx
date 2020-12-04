#include <iostream>
#include <map>
#include <cstdint>

std::map<uint_fast64_t, uint_fast64_t> PrimeFactorization(uint_fast64_t num){
  std::map<uint_fast64_t, uint_fast64_t> prime_factors;
  for(uint_fast64_t i = 2 ; i * i <= num ; ){
    if(num % i == 0){
      num /= i;
      prime_factors[i]++;
    }else{
      i++;
    }
  }
  if(num > 1){
      prime_factors[num]++;
  }
  return prime_factors;
}

int main(int argc, char *argv[]){
  uint_fast64_t num = atoi(argv[1]);
  std::map<uint_fast64_t, uint_fast64_t> a = PrimeFactorization(num);

  if(num <= 1){
    std::cout << num << std::endl;
    return 0;
  }
  
  for(auto it = a.begin() ; it != a.end() ; it++){
    if(it -> second == 1){
      std::cout << it -> first;
    }else{
      std::cout << it -> first << "^" << it -> second;
    }
    if(std::next(it, 1) != a.end() ){
      std::cout << " * ";
    }
  }
  std::cout << std::endl;
  return 0;
}

#include "google_password.h"

#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::endl;

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {

  if(validPassword(password) == true){
    Usuario usuario_ = {login, password};
    passwords_.insert(std::make_pair(url, usuario_));
  }
}

void GooglePassword::remove(const std::string& url) {
  passwords_.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {

  auto it = passwords_.find(url);

  if((it != passwords_.end()) && (validPassword(new_password) == true) && (it->second.password == old_password)){
      it->second.login = login;
      it->second.password = new_password;
  }
}

void GooglePassword::printPasswords() {
  cout << passwords_.size() << endl;

  for(auto it = passwords_.begin(); it != passwords_.end(); it++){
    cout << it->first << ": " << it->second.login << " and " << it->second.password << endl;
  }
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */
}

bool GooglePassword::validPassword(const std::string& password) const {
  bool senhaValida = true;

  if((password.length() < 6) || (password.length() > 50)){
      senhaValida = false;
  }
  for(int i=0; i < password.size(); i++){
    if((password[i] == ' ') || (password[i] == '1' && password[i+1] == '2' &&
      password[i+2] == '3' && password[i+3] == '4' && password[i+4] == '5' &&
      password[i+5] == '6')){
      senhaValida = false;
    }
  }
  return senhaValida;
}


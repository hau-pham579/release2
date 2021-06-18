#ifndef __ETUDIANT_HPP_
#define __ETUDIANT_HPP_
#include <string>
#include <vector>
using namespace std;

class Etudiant {
  private:
    std::vector<int> notes;
    std::string identifiant;
    long matricule;
  public:
    Etudiant(){};
    Etudiant(std::string un_identifiant, long un_matricule){
      this->identifiant = un_identifiant;
      this->matricule = un_matricule; 
    }     
      
    double calculerMoyenne();

    void ajouterNote(std::vector<int>& pointes, int la_note)
    {pointes.push_back(la_note);}   

};

#endif
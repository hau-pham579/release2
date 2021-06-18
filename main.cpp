#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include "Etudiant.hpp"
using namespace std;

double calculerMoyenne(int totalpoints, int nb);

int main() {
  

  std::vector<int> notes;  
  std::vector<Etudiant> etudiant;  
  std::map<long,double> les_dossiers;  
  fstream lecteur;
  lecteur.open("C:/Users/haudu/.vscode/projet1/TP2/donneesbrutes.txt",ios::in);
  ofstream ecrivain;
  ecrivain.open("C:/Users/haudu/.vscode/projet1/TP2/moyennes.txt",ios::out);

  if (!lecteur) {
    cout<< "erreur d'ouverture du fichier d'entree";
    return 0;
  }  
  string ligne;
  int somme;
  
  while(!lecteur.eof()){
    getline(lecteur, ligne);
    if(lecteur.eof()==true) break;
    istringstream lire(ligne);
    
    string nom;
    lire>>nom; 
    if(lecteur.eof()==true) break;   
   
    long matric;
    lire>>matric;  
    if(lecteur.eof()==true) break;
    
    Etudiant un_etudiant(nom, matric);
  
    int nbcours;
    lire>>nbcours;
    if(lecteur.eof()==true) break;
    int une_note;
    
    somme=0;
    for (int i=0; i<nbcours ; i++){      
       lire>>une_note;
       if(lecteur.eof()==true) break;
       un_etudiant.ajouterNote(notes, une_note); 
       somme = somme + une_note;          
    }

    etudiant.push_back(un_etudiant);
  
    double moyenne = calculerMoyenne(somme, nbcours);
    
    les_dossiers[matric] = moyenne;
 
  }
  std::map<long,double> second (les_dossiers.begin(), les_dossiers.end()); 
  map<long,double> ::iterator mon_iter ;
  for (mon_iter=les_dossiers.begin(); mon_iter !=les_dossiers.end(); mon_iter++){
     
     ecrivain<<mon_iter->first<<" "<<mon_iter->second<<endl;
  }  
  lecteur.close();
  ecrivain.close();
  return 0;
}

double calculerMoyenne(int totalpoints, int nb){
      
      double moyen = (double) totalpoints / nb;
      return moyen;       
}


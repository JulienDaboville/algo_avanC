package arbre;

class Noeud {
    int donnee;
    Noeud gauche;
    Noeud droit;

    public Noeud(int donnee) {
        this.donnee = donnee;
        this.gauche = null;
        this.droit = null;
    }
}

public class GenerateurArbresBinaires {
    public static void genererEtAfficherTousLesArbresBinaires(int n) {
        Noeud[] arbres = genererArbresBinaires(1, n);
        for (Noeud arbre : arbres) {
            afficherArbre(arbre, 0);
            System.out.println("\n--------------------");
        }
    }

    public static Noeud[] genererArbresBinaires(int debut, int fin) {
        if (debut > fin) {
            Noeud[] arbres = { null };
            return arbres;
        }

        Noeud[] resultat = new Noeud[0];

        for (int i = debut; i <= fin; i++) {
            Noeud[] arbresGauche = genererArbresBinaires(debut, i - 1);
            Noeud[] arbresDroit = genererArbresBinaires(i + 1, fin);

            for (Noeud gauche : arbresGauche) {
                for (Noeud droit : arbresDroit) {
                    Noeud racine = new Noeud(i);
                    racine.gauche = gauche;
                    racine.droit = droit;
                    resultat = ajouterArbre(resultat, racine);
                }
            }
        }

        return resultat;
    }

    public static Noeud[] ajouterArbre(Noeud[] arbres, Noeud arbre) {
        Noeud[] nouveauxArbres = new Noeud[arbres.length + 1];
        for (int i = 0; i < arbres.length; i++) {
            nouveauxArbres[i] = arbres[i];
        }
        nouveauxArbres[arbres.length] = arbre;
        return nouveauxArbres;
    }

    public static void afficherArbre(Noeud racine, int niveau) {
        if (racine == null) {
            return;
        }

        afficherArbre(racine.droit, niveau + 1);
        for (int i = 0; i < niveau; i++) {
            System.out.print("   ");
        }
        System.out.println(racine.donnee);
        afficherArbre(racine.gauche, niveau + 1);
    }

    public static void main(String[] args) {
        int n = 4;
        genererEtAfficherTousLesArbresBinaires(n);
    }
}


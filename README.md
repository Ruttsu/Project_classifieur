# poo

TUTO synchro avec le git insa (sur git bash ou autres):
-eval $(ssh-agent -s) //lance l'agent ssh (ou le redemarre)
-ssh-keygen -t rsa -b 4096 -C "votre_email@example.com" // génère clef privé et clef publique (.pub), pas besoin de passphrase
-ssh-add /chemin/vers/votre/cle-privee //ajouter sa clef PRIVE a son agent ssh perso
-https://github.com/settings/keys  //ajouter sa clef PUBLIQUE à github pour finaliser la config de la paire

Sur ma branche, nécessaire d'installer Mingw avec la feature make pour run 
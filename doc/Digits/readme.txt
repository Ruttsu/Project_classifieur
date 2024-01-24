L'archive comprends:
- un fichier lismoi.txt (moi même)
- un fichier digits.svm: les données d'apprentissage au format svm:
>--- la première ligne indique le nombre d'examples dans le fichier
>--- la seconde le nombre de caratéristiques de chaque example, les caractéristiques sont des informations liées au déplacement du stylet sur la tablette
>--- le nombre de colonnes dans le fichier est donc 1 (l'étiquette à prédire en colonne 1) plus le chiffre précédent
>--- puis chaque ligne correspond à un example, le premier numéro correspond au numéro de la classe, ici c'est équivalent à la classe elle même car les classes sont les numéros [0-9], puis suivent les caractéristiques de l'example.
- un répertoire images_digits contenant les tracés, dans le même ordre que le fichier d'apprentissage
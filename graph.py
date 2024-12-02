import pandas as pd
import matplotlib.pyplot as plt


def sort_file_lines_by_first_number(filename):
    # Lire toutes les lignes du fichier
    with open(filename, 'r') as file:
        lines = file.readlines()

    # Conserver l'en-tête (la première ligne)
    header = lines[0]

    # Trier les lignes restantes en fonction du premier nombre de chaque ligne
    # On ignore la première ligne (l'en-tête) en faisant un slice lines[1:]
    lines_to_sort = lines[1:]

    # Trier les lignes restantes en fonction du premier nombre
    lines_to_sort.sort(key=lambda line: int(line.split(';')[0]))  # Assurez-vous que le séparateur est correct (ici ';')

    # Réécrire le fichier avec l'en-tête en premier, puis les lignes triées
    with open(filename, 'w') as file:
        file.write(header)  # Écrire l'en-tête
        file.writelines(lines_to_sort)  # Écrire les lignes triées

# Fonction pour charger les données depuis un fichier CSV
def load_data(file_path):
    # Charger le CSV dans un DataFrame pandas
    df = pd.read_csv(file_path, sep=';')

    # Convertir toutes les colonnes de temps (à partir de la 2ème colonne) en entiers
    for column in df.columns[1:]:
        df[column] = df[column].apply(lambda x: int(x))  # Convertir en entiers (enlever les décimales)

    return df

# Fonction pour tracer les courbes à partir des données
def plot_graph(df):
    # Créer un graphique avec plusieurs courbes
    plt.figure(figsize=(10, 6))

    # La première colonne est la longueur des tableaux
    x = df.iloc[:, 0]  # Longueur des tableaux (1ère colonne)

    # Tracer chaque courbe à partir des autres colonnes (temps en ns)
    for column in df.columns[1:]:
        plt.plot(x, df[column], label=column)

    # Ajouter des labels et un titre
    plt.xlabel('Array size')
    plt.ylabel('Time ns')
    plt.title('time for sort with size')

    # Ajouter une légende pour identifier les courbes
    plt.legend()

    # Formatage de l'axe des ordonnées pour afficher les nombres sans décimales
    plt.gca().yaxis.set_major_formatter(plt.FuncFormatter(lambda x, loc: f'{int(x):,}'))  # Ajout de la virgule pour une meilleure lisibilité

    # Formatage de l'axe des abscisses pour afficher les nombres sans notation scientifique
    plt.gca().xaxis.set_major_formatter(plt.FuncFormatter(lambda x, loc: f'{int(x):,}'))  # Utilisation de la virgule pour la lisibilité

    # Afficher le graphique
    plt.grid(True)
    plt.show()

    # Sauvegarder le graphique en PNG
    plt.savefig('sort.png')  # Sauvegarder l'image

def main():

    # Spécifier le chemin vers ton fichier CSV et le trié
    file_path = 'sort_time.csv'  # Remplace par le chemin de ton fichier CSV
    sort_file_lines_by_first_number(file_path)

    # Charger les données depuis le fichier CSV
    df = load_data(file_path)

    # Tracer le graphique avec les données
    plot_graph(df)

# Lancer le programme
if __name__ == "__main__":
    main()

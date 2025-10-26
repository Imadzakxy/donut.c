# 🍩 ASCII Donut 3D – Animation en C

Ce projet affiche un **donut (tore) en 3D ASCII** tournant dans le terminal, rendu à l’aide de formules trigonométriques et d’un modèle simple d’éclairage Lambertien.  
Le programme calcule la position et la luminosité de chaque point de la surface du tore, puis le projette en 2D à chaque frame pour créer une animation fluide.

---

## 📁 Structure du projet
```plaintext
├── include/
│   ├── draw.h
│   └── rotation.h
│
├── src/
│   ├── draw.c
│   └── rotation.c
│
└── main.c
```

---

## ⚙️ Fonctionnalités principales

- Donut ASCII 3D animé dans le terminal  
- Rotation fluide sur deux axes (`X` et `Y`)  
- Palette de caractères simulant la profondeur et la lumière  
- Nettoyage et rafraîchissement automatique de l’écran  
- Code modulaire et facilement modifiable  

---


## 🧮 Principe mathématique

Le donut est défini par deux rayons :
- `R` : rayon principal (distance du centre du tore)
- `r` : rayon du tube

Chaque point du tore est décrit par deux angles `θ` et `ϕ` :

\[
x = (R + r \cosθ) \cosϕ
\]
\[
y = (R + r \cosθ) \sinϕ
\]
\[
z = r \sinθ
\]

Ensuite, on applique des **rotations** sur deux axes à l’aide des fonctions :

\[
x' = x \cos(B) + z \sin(B)
\]
\[
y' = y \cos(A) - z \sin(A)
\]

Ces nouvelles coordonnées sont projetées sur le plan 2D pour être affichées sous forme de caractères ASCII.  
Chaque caractère correspond à une **intensité lumineuse simulée**, créant une illusion de profondeur.


---

## 🧰 Compilation

Compiler le projet avec **gcc** :

```bash
gcc main.c src/draw.c src/rotation.c -Iinclude -o donut -lm
```

Compiler le projet avec **Makefile**:

```bash
make

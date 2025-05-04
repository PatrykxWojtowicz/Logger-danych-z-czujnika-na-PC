import cv2
import pytesseract
from pathlib import Path


INPUT_DIR = Path(r"C:\Users\patry\OneDrive\Documents\Programowanie\VSCODE.programy\Programy_VS_Code\OCR-tool\test")
OUTPUT_DIR = Path(r"C:\Users\patry\OneDrive\Documents\Programowanie\VSCODE.programy\Programy_VS_Code\OCR-tool\output_md")
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)


OCR_LANG = 'deu'


HEADER = "|Nr|Opis|"
SEPARATOR = "|--|-----|"

def process_image(image_path):
    img = cv2.imread(str(image_path), cv2.IMREAD_GRAYSCALE)
    img = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                                 cv2.THRESH_BINARY, 11, 2)
    text = pytesseract.image_to_string(img, lang=OCR_LANG)
    lines = [l.strip() for l in text.splitlines() if l.strip()]
    data = []
    for i, line in enumerate(lines, start=1):
        data.append((str(i), line))
    return data

def main():
    for path in INPUT_DIR.glob("*.png"):
        rows = process_image(path)
        md_path = OUTPUT_DIR / f"{path.stem}.md"
        with open(md_path, "w", encoding="utf-8") as f:
            f.write(HEADER + "\n")
            f.write(SEPARATOR + "\n")
            for nr, opis in rows:
                f.write(f"|{nr}|{opis}|\n")
        print(f"Zapisano: {md_path}")

if __name__ == "__main__":
    main()

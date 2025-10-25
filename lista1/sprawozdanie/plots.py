import matplotlib.pyplot as plt
import pandas as pd
from pathlib import Path

def string_to_list(string):
    list = [int(x) for x in string.split()]
    return list

base = Path(__file__).parent
file_path = base / "results_for_insertion"


size = list(range(10,2000))


file_path = base / "results_for_insertion.txt"
f = open(file_path, "r", encoding="utf-8")
insertion_results = f.read()
f.close()

file_path = base / "results_for_insertion_pairs.txt"
f = open(file_path, "r", encoding="utf-8")
insertion_pairs_results = f.read()
f.close()

file_path = base / "results_for_merge.txt"
f = open(file_path, "r", encoding="utf-8")
merge_results = f.read()
f.close()

file_path = base / "results_for_merge_3.txt"
f = open(file_path, "r", encoding="utf-8")
merge_3_results = f.read()  
f.close()

file_path = base / "results_for_heap.txt"
f = open(file_path, "r", encoding="utf-8")
heap_results = f.read()
f.close()

file_path = base / "results_for_heap_3.txt"
f = open(file_path, "r", encoding="utf-8")
heap_3_results = f.read()
f.close()

insertion_results = string_to_list(insertion_results)
insertion_pairs_results = string_to_list(insertion_pairs_results)
merge_results = string_to_list(merge_results)
merge_3_results = string_to_list(merge_3_results)
heap_results = string_to_list(heap_results)
heap_3_results = string_to_list(heap_3_results)




df = pd.DataFrame({
    "size": size,
    "Insertion Sort":        insertion_results,
    "Insertion Sort Pairs":  insertion_pairs_results,
    "Merge Sort":            merge_results,
    "Merge Sort_3":          merge_3_results,
    "Heap Sort":             heap_results,
    "Heap Sort_3":           heap_3_results,
}).sort_values(by="size").reset_index(drop=True)


plt.figure(figsize=(10,10))
for col in df.columns:
    if col != "size":
        plt.plot(df["size"], df[col], marker="o", label=col)
plt.xlabel("Rozmiar tablicy (n)")
plt.ylabel("Liczba operacji")
plt.title("Porównanie algorytmów sortowania (pełny zestaw)")
plt.legend()
plt.grid(True)
plt.ticklabel_format(style='plain', axis='y')
plt.tight_layout()
plt.savefig(base / "operations_all.png", dpi=200)
# plt.show()


for col in df.columns:
    if col == "size":
        continue
    plt.figure(figsize=(10,10))
    plt.plot(df["size"], df[col], marker="o", label=col)
    plt.ylim(0, 1000000)
    plt.xlabel("Rozmiar tablicy (n)")
    plt.ylabel("Liczba operacji")
    plt.title(f"{col}: liczba operacji vs n")
    plt.legend()
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')
    plt.tight_layout()
    fname = col.lower().replace(" ", "_") + ".png"
    plt.savefig(base / fname, dpi=200)
    # plt.show()
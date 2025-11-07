import matplotlib.pyplot as plt
import pandas as pd
from pathlib import Path

def string_to_list(string):
    list = [int(x) for x in string.split()]
    return list

base = Path(__file__).parent
file_path = base / "results_for_insertion"


size = list(range(1000,200000,1000))

def read_results(fname):
    p = base / fname
    f = open(p, "r", encoding="utf-8")
    data = f.read()
    f.close()
    return string_to_list(data)


# file_path = base / "results_for_insertion.txt"
# f = open(file_path, "r", encoding="utf-8")
# insertion_results = f.read()
# f.close()

# file_path = base / "results_for_insertion_pairs.txt"
# f = open(file_path, "r", encoding="utf-8")
# insertion_pairs_results = f.read()
# f.close()

# file_path = base / "results_for_merge.txt"
# f = open(file_path, "r", encoding="utf-8")
# merge_results = f.read()
# f.close()

# file_path = base / "results_for_merge_3.txt"
# f = open(file_path, "r", encoding="utf-8")
# merge_3_results = f.read()  
# f.close()

# file_path = base / "results_for_heap.txt"
# f = open(file_path, "r", encoding="utf-8")
# heap_results = f.read()
# f.close()

# file_path = base / "results_for_heap_3.txt"
# f = open(file_path, "r", encoding="utf-8")
# heap_3_results = f.read()
# f.close()

# insertion_results = string_to_list(insertion_results)
# insertion_pairs_results = string_to_list(insertion_pairs_results)
# merge_results = string_to_list(merge_results)
# merge_3_results = string_to_list(merge_3_results)
# heap_results = string_to_list(heap_results)
# heap_3_results = string_to_list(heap_3_results)

insertion_results_assign = read_results("results_for_insertion.txt")
insertion_pairs_results_assign = read_results("results_for_insertion_pairs.txt")
merge_results_assign = read_results("results_for_merge.txt")
merge_3_results_assign = read_results("results_for_merge_3.txt")
heap_results_assign = read_results("results_for_heap.txt")
heap_3_results_assign = read_results("results_for_heap_3.txt")

insertion_results_comparison = read_results("results_comparison_for_insertion.txt")
insertion_pairs_results_comparison = read_results("results_comparison_for_insertion_pairs.txt")
merge_results_comparison = read_results("results_comparison_for_merge.txt")
merge_3_results_comparison = read_results("results_comparison_for_merge_3.txt")
heap_results_comparison = read_results("results_comparison_for_heap.txt")
heap_3_results_comparison = read_results("results_comparison_for_heap_3.txt")



df_assign = pd.DataFrame({
    "size": size,
    "Insertion Sort":        insertion_results_assign,
    "Insertion Sort Pairs":  insertion_pairs_results_assign,
    "Merge Sort":            merge_results_assign,
    "Merge Sort_3":          merge_3_results_assign,
    "Heap Sort":             heap_results_assign,
    "Heap Sort_3":           heap_3_results_assign,
}).sort_values(by="size").reset_index(drop=True)

df_comparison = pd.DataFrame({
    "size": size,
    "Insertion Sort":        insertion_results_comparison,
    "Insertion Sort Pairs":  insertion_pairs_results_comparison,
    "Merge Sort":            merge_results_comparison,
    "Merge Sort_3":          merge_3_results_comparison,
    "Heap Sort":             heap_results_comparison,
    "Heap Sort_3":           heap_3_results_comparison,
})


plt.figure(figsize=(10,10))
for col in df_assign.columns:
    if col != "size":
        plt.plot(df_assign["size"], df_assign[col], marker="o", label=col)
plt.xlabel("Rozmiar tablicy (n)")
plt.ylabel("Liczba przypisań")
plt.title("Porównanie algorytmów sortowania po liczbie przypisań")
plt.legend()
plt.grid(True)
plt.ticklabel_format(style='plain', axis='y')
plt.tight_layout()
plt.savefig(base / "operations_all.png", dpi=200)
# plt.show()

plt.figure(figsize=(10,10))
for col in df_comparison.columns:
    if col != "size":
        plt.plot(df_comparison["size"], df_comparison[col], marker="o", label=col)
plt.xlabel("Rozmiar tablicy (n)")
plt.ylabel("Liczba porównań")
plt.title("Porównanie algorytmów sortowania po liczbie porównań")
plt.legend()
plt.grid(True)
plt.ticklabel_format(style='plain', axis='y')
plt.tight_layout()
plt.savefig(base / "operations_all_comparison.png", dpi=200)


for col in df_assign.columns[1::2]:
    current_col_index = df_assign.columns.get_loc(col)        
    next_col = df_assign.columns[current_col_index + 1] 
    plt.figure(figsize=(10,10))
    plt.plot(df_assign["size"], df_assign[col], marker="o", label=col)
    plt.plot(df_assign["size"], df_assign[next_col], marker="o", label=next_col)
    plt.xlabel("Rozmiar tablicy (n)")
    plt.ylabel("Liczba operacji")
    plt.title(f"{col} vs {next_col} - liczba przypisań")
    plt.legend()
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')
    plt.tight_layout()
    fname = col.lower().replace(" ", "_")+ "_vs_" + next_col.lower().replace(" ", "_") + ".png"
    plt.savefig(base / fname, dpi=200)
    
for col in df_comparison.columns[1::2]:
    current_col_index = df_comparison.columns.get_loc(col)        
    next_col = df_comparison.columns[current_col_index + 1] 
    plt.figure(figsize=(10,10))
    plt.plot(df_comparison["size"], df_comparison[col], marker="o", label=col)
    plt.plot(df_comparison["size"], df_comparison[next_col], marker="o", label=next_col)
    plt.xlabel("Rozmiar tablicy (n)")
    plt.ylabel("Liczba operacji")
    plt.title(f"{col} vs {next_col} - liczba porównań")
    plt.legend()
    plt.grid(True)
    plt.ticklabel_format(style='plain', axis='y')
    plt.tight_layout()
    fname = col.lower().replace(" ", "_")+ "_vs_" + next_col.lower().replace(" ", "_") + "_comparison.png"
    plt.savefig(base / fname, dpi=200)

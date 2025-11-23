import os
import numpy as np
import matplotlib.pyplot as plt




def load_data(filename):
    path = os.path.join(filename)
    data = np.loadtxt(path)

    n = data[:, 0]
    comparisons = data[:, 1]
    assignments = data[:, 2]
    return n, comparisons, assignments

quick_sort_n, quick_sort_c, quick_sort_a = load_data("quick_sort_data.txt")
quick_sort_2_n, quick_sort_2_c, quick_sort_2_a = load_data("quick_sort_2_divider_data.txt")

radix_2_n, radix_2_c, radix_2_a = load_data("radix_sort_2_data.txt")
radix_10_n, radix_10_c, radix_10_a = load_data("radix_sort_10_data.txt")
radix_16_n, radix_16_c, radix_16_a = load_data("radix_sort_16_data.txt")

bucket_sort_all_random_n, bucket_sort_all_random_c, bucket_sort_all_random_a = load_data("bucket_sort_for_all_data.txt")
bucket_sort_all_classic_n, bucket_sort_all_classic_c, bucket_sort_all_classic_a = load_data("bucket_sort_for_all_classic_data.txt")

# all comprasisons plot
plt.figure()
plt.plot(quick_sort_n, quick_sort_c, marker="o", label="Quick sort (classic)")
plt.plot(quick_sort_2_n, quick_sort_2_c, marker="o", linestyle="--", label="Quick sort (2 dividers)")
plt.plot(radix_2_n, radix_2_c, marker="x", label="Radix sort base 2")
plt.plot(radix_10_n, radix_10_c, marker="x", linestyle="--", label="Radix sort base 10")
plt.plot(radix_16_n, radix_16_c, marker="x", linestyle=":", label="Radix sort base 16")

plt.xlabel("n")
plt.ylabel("Number of comparisons")
plt.title("Comparisons vs n (integer sorting algorithms)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("comparisons_int_sorts.png", dpi=200)

# all assignments plot
plt.figure()
plt.plot(quick_sort_n, quick_sort_a, marker="o", label="Quick sort (classic)")
plt.plot(quick_sort_2_n, quick_sort_2_a, marker="o", linestyle="--", label="Quick sort (2 dividers)")
plt.plot(radix_2_n, radix_2_a, marker="x", label="Radix sort base 2")
plt.plot(radix_10_n, radix_10_a, marker="x", linestyle="--", label="Radix sort base 10")
plt.plot(radix_16_n, radix_16_a, marker="x", linestyle=":", label="Radix sort base 16")

plt.xlabel("n")
plt.ylabel("Number of assignments")
plt.title("Assignments vs n (integer sorting algorithms)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("assignments_int_sorts.png", dpi=200)

# bucket sort comparisons plot
plt.figure()
plt.plot(
    bucket_sort_all_random_n,
    bucket_sort_all_random_c,
    marker="o",
    label="Bucket sort for all (0..100000)",
)
plt.plot(
    bucket_sort_all_classic_n,
    bucket_sort_all_classic_c,
    marker="o",
    linestyle="--",
    label="Bucket sort for all [0,1)",
)

plt.xlabel("n")
plt.ylabel("Number of comparisons")
plt.title("Comparisons vs n (bucket sort variants)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("comparisons_bucket.png", dpi=200)


# bucket sort assignment plot
plt.figure()
plt.plot(
    bucket_sort_all_random_n,
    bucket_sort_all_random_a,
    marker="o",
    label="Bucket sort for all (0..100000)",
)
plt.plot(
    bucket_sort_all_classic_n,
    bucket_sort_all_classic_a,
    marker="o",
    linestyle="--",
    label="Bucket sort for all [0,1)",
)

plt.xlabel("n")
plt.ylabel("Number of assignments")
plt.title("Assignments vs n (bucket sort variants)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("assignments_bucket.png", dpi=200)


# radix comparisons for different bases
plt.figure()
plt.plot(radix_2_n, radix_2_c, marker="o", label="Radix sort, base = 2")
plt.plot(radix_10_n, radix_10_c, marker="o", linestyle="--", label="Radix sort, base = 10")
plt.plot(radix_16_n, radix_16_c, marker="o", linestyle=":", label="Radix sort, base = 16")

plt.xlabel("n")
plt.ylabel("Number of comparisons")
plt.title("RADIX_SORT – porównanie liczby porównań dla różnych podstaw d")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("radix_comparisons_bases.png", dpi=200)

# radix assignments for different bases
plt.figure()
plt.plot(radix_2_n, radix_2_a, marker="o", label="Radix sort, base = 2")
plt.plot(radix_10_n, radix_10_a, marker="o", linestyle="--", label="Radix sort, base = 10")
plt.plot(radix_16_n, radix_16_a, marker="o", linestyle=":", label="Radix sort, base = 16")

plt.xlabel("n")
plt.ylabel("Number of assignments")
plt.title("RADIX_SORT – porównanie liczby przypisań dla różnych podstaw d")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("radix_assignments_bases.png", dpi=200)

# quick/quick2/bucket comparisons
plt.figure()
plt.plot(quick_sort_n, quick_sort_c, marker="o", label="Quick sort (classic)")
plt.plot(quick_sort_2_n, quick_sort_2_c, marker="o", linestyle="--", label="Quick sort (2 pivots)")
plt.plot(
    bucket_sort_all_random_n,
    bucket_sort_all_random_c,
    marker="x",
    linestyle=":",
    label="Bucket sort for all (0..100000)",
)

plt.xlabel("n")
plt.ylabel("Number of comparisons")
plt.title("Porównanie QUICK_SORT i BUCKET_SORT (losowe dane, zakres 0..100000)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("quick_vs_bucket_random_comparisons.png", dpi=200)


# quick/quick2/bucket comparisons
plt.figure()
plt.plot(quick_sort_n, quick_sort_a, marker="o", label="Quick sort (classic)")
plt.plot(quick_sort_2_n, quick_sort_2_a, marker="o", linestyle="--", label="Quick sort (2 pivots)")
plt.plot(
    bucket_sort_all_random_n,
    bucket_sort_all_random_a,
    marker="x",
    linestyle=":",
    label="Bucket sort for all (0..100000)",
)

plt.xlabel("n")
plt.ylabel("Number of assignments")
plt.title("Porównanie QUICK_SORT i BUCKET_SORT – liczba przypisań (0..100000)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("quick_vs_bucket_random_assignments.png", dpi=200)


# Made too many plots, and didn't use them after, but still they are generated here
from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt


here = Path(__file__).resolve().parent


root = here.parents[1]   


csv_path = root / "data.csv"            
out_dir  = root / "sprawozdanie" / "plots"  


out_dir.mkdir(parents=True, exist_ok=True)

df = pd.read_csv(csv_path, encoding="utf-16")
df = df.sort_values(["problem", "algo", "n"])

for problem in df["problem"].unique():
    sub = df[df["problem"] == problem]

    for metric in ["cmp", "assign"]:
        plt.figure()

        for algo in sub["algo"].unique():
            data = sub[sub["algo"] == algo]
            plt.plot(data["n"], data[metric], marker="o", label=algo)

        plt.xlabel("n")
        plt.ylabel(metric)
        plt.title(f"{problem}: {metric} vs n")

        if problem == "CUT_ROD":
            plt.yscale("log")

        plt.grid(True)
        plt.legend()
        plt.tight_layout()

        filename = f"{problem}_{metric}.png"
        plt.savefig(out_dir / filename, dpi=200)
        plt.close()


# some more plots for fast versions oof activity selector

fast_algos = ["as_rec", "as_iter"]

activity = df[df["problem"] == "ACTIVITY"]

for metric in ["cmp", "assign"]:
    plt.figure()

    for algo in fast_algos:
        data = activity[activity["algo"] == algo]
        plt.plot(
            data["n"],
            data[metric],
            marker="o",
            label=algo
        )

    plt.xlabel("n")
    plt.ylabel(metric)
    plt.title(f"ACTIVITY (fast only): {metric} vs n")

    plt.grid(True)
    plt.legend()
    plt.tight_layout()

    filename = f"ACTIVITY_fast_{metric}.png"
    plt.savefig(out_dir / filename, dpi=200)
    plt.close()



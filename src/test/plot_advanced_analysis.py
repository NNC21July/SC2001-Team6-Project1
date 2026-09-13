import pandas as pd
import matplotlib.pyplot as plt
import sys
import math

def plot_final_analysis():
    try:
        df = pd.read_csv("advanced_results.csv", encoding='utf-16')
    except FileNotFoundError:
        print("Error: advanced_results.csv not found.")
        sys.exit(1)

    df.columns = df.columns.str.strip()

    n_values = df['n'].unique()
    n_values.sort()

    num_plots = len(n_values)
    num_cols = 2 
    num_rows = math.ceil(num_plots / num_cols)
    
    fig, axes = plt.subplots(num_rows, num_cols, figsize=(15, 7 * num_rows), squeeze=False)
    fig.suptitle('Optimal S Analysis for Different Input Sizes', fontsize=16, y=1.02)

    axes = axes.flatten()

    for i, n_val in enumerate(n_values):
        ax = axes[i]
        subset = df[df['n'] == n_val].sort_values('S')
        
        # Plot S vs. comparisons for this subset
        ax.plot(subset['S'], subset['comparisons'], marker='o', linestyle='-', label=f'Data for n = {n_val}')
        
        # Find and highlight the optimal S for this n
        if not subset.empty:
            optimal_s_row = subset.loc[subset['comparisons'].idxmin()]
            optimal_s = int(optimal_s_row['S'])
            min_comparisons = int(optimal_s_row['comparisons'])
            
            ax.axvline(x=optimal_s, color='r', linestyle='--', label=f"Optimal S = {optimal_s}")
            print(f"For n = {n_val}, the optimal S is {optimal_s} with {min_comparisons} comparisons.")
        
        ax.set_title(f'Analysis for n = {n_val}')
        ax.set_xlabel('Threshold (S)')
        ax.set_ylabel('Number of Key Comparisons')
        ax.grid(True)
        ax.legend()

    for j in range(i + 1, len(axes)):
        fig.delaxes(axes[j])

    plt.tight_layout(rect=[0, 0.03, 1, 0.98])
    plt.savefig('final_optimal_s_analysis.png')
    plt.show()

if __name__ == '__main__':
    plot_final_analysis()

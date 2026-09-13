import pandas as pd
import matplotlib.pyplot as plt
import sys

def plot_graphs():
    try:
        df = pd.read_csv("results.csv", encoding='utf-16')
    except FileNotFoundError:
        print("Error: results.csv not found in this folder.")
        print("Please ensure results.csv is in the same directory as this script.")
        sys.exit(1)

    df.columns = df.columns.str.strip()

    #Graph 1: Comparisons vs. Input Size (n) for S = 16
    exp1_data = df[df['S'] == 16].sort_values('n')

    if not exp1_data.empty:
        plt.figure(figsize=(10, 6))
        plt.plot(exp1_data['n'], exp1_data['comparisons'], marker='o', linestyle='-', color='b')
        plt.title('Performance Analysis (S = 16)')
        plt.xlabel('Input Size (n)')
        plt.ylabel('Number of Key Comparisons')
        plt.grid(True, which="both", ls="-")
        plt.xscale('log') 
        plt.yscale('log') 
        plt.savefig('comparisons_vs_n.png', dpi=300)
        print("✅ Generated graph: comparisons_vs_n.png")
        plt.close()
    else:
        print("❌ Could not generate Graph 1: No data found for S = 16.")

    #Graph 2: Comparisons vs. S Threshold for n = 100000
    exp2_data = df[df['n'] == 100000].sort_values('S')

    if not exp2_data.empty:
        plt.figure(figsize=(10, 6))
        plt.plot(exp2_data['S'], exp2_data['comparisons'], marker='o', linestyle='-', color='g')
        plt.title('Optimal S Analysis (n = 100,000)')
        plt.xlabel('Threshold (S)')
        plt.ylabel('Number of Key Comparisons')
        plt.grid(True)
        
        #Highlight the optimal S (the one with the lowest comparisons)
        optimal_s_row = exp2_data.loc[exp2_data['comparisons'].idxmin()]
        optimal_s = optimal_s_row['S']
        plt.axvline(x=optimal_s, color='r', linestyle='--', label=f"Optimal S = {int(optimal_s)}")
        plt.legend()

        plt.savefig('comparisons_vs_s.png', dpi=300)
        print("✅ Generated graph: comparisons_vs_s.png")
        plt.close()
    else:
        print("❌ Could not generate Graph 2: No data found for n = 100,000.")

if __name__ == '__main__':
    plot_graphs()

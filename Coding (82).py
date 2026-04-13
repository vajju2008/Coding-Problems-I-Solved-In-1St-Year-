import pandas as pd

def load_flight_data(filename):
    return pd.read_csv(filename)

def clean_data(df):
    df["released"] = pd.to_datetime(df["released"])
    df = df.dropna(subset=["gross"])
    return df

def optimize_memory(df):
    for col in ["rating", "genre", "country", "company"]:
        df[col] = df[col].astype("category")
    return df

def rank_studios(df):
    grouped = (
        df.groupby("company", observed=True)["gross"]
        .sum()
        .to_frame(name="Total_Gross")
    )
    grouped["Rank"] = grouped["Total_Gross"].rank(
        ascending=False, method="min"
    )
    return grouped.sort_values("Rank")

def calculate_industry_growth(df):
    df_sorted = df.sort_values("released")
    df_sorted["cumulative_industry_gross"] = df_sorted["gross"].expanding().sum()
    return df_sorted[["released", "name", "gross", "cumulative_industry_gross"]]

def analyze_recent_trends(df):
    df_sorted = df.sort_values("released")
    df_sorted["rolling_avg_3_movies"] = (
        df_sorted["gross"].rolling(3).mean().fillna(0)
    )
    return df_sorted[["released", "name", "gross", "rolling_avg_3_movies"]]

# ai_complexity.py
import sys
import openai

openai.api_key = "YOUR_API_KEY"  # Use env var if you prefer

def read_func(path):
    with open(path, 'r') as f:
        return f.read()

def ask_ai(function_code):
    prompt = f"What is the time complexity of this function?\n\n{function_code}\n\nJust reply with Big-O notation and a short explanation."
    response = openai.ChatCompletion.create(
        model="gpt-4",
        messages=[{"role": "user", "content": prompt}]
    )
    return response.choices[0].message.content.strip()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ai_complexity.py <function_file>")
        sys.exit(1)

    func_code = read_func(sys.argv[1])
    result = ask_ai(func_code)
    print(result)

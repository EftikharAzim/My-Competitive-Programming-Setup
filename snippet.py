import json
import os

# Paths (adjust if needed)
template_path = "template.cpp"
snippets_dir = os.path.expanduser("~/Library/Application Support/Code/User/snippets")  # Mac
cpp_snippet_file = os.path.join(snippets_dir, "cpp.json")

# Read template.cpp
with open(template_path, "r", encoding="utf-8") as f:
    template_lines = f.read().splitlines()

# Load existing snippets if file exists
if os.path.exists(cpp_snippet_file):
    with open(cpp_snippet_file, "r", encoding="utf-8") as f:
        try:
            snippets = json.load(f)
        except json.JSONDecodeError:
            snippets = {}
else:
    snippets = {}

# Update snippet
snippets["CPT Template"] = {
    "prefix": "cpt",
    "body": template_lines,
    "description": "Competitive Programming template"
}

# Save back
with open(cpp_snippet_file, "w", encoding="utf-8") as f:
    json.dump(snippets, f, indent=2)

print(f"✅ Snippet updated in {cpp_snippet_file}")

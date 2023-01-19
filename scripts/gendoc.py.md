---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/suisen-cp/cp-library-cpp/blob/main/scripts/generate_doc_files.py
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\n# https://github.com/suisen-cp/cp-library-cpp/blob/main/scripts/generate_doc_files.py\n\
    \nimport argparse\nimport colorlog\nimport logging\nfrom pathlib import Path\n\
    import textwrap\n\n\ndef generate(src_file: Path):\n    doc_path = (doc_root /\
    \ src_file).with_suffix(\".md\")\n\n    if doc_path.exists():\n        logger.debug(f\"\
    File '{doc_path}' already exists.\")\n        return\n    logger.info(f\"Generate\
    \ file '{doc_path}'.\")\n\n    doc_path.parent.mkdir(parents=True, exist_ok=True)\n\
    \    doc_path.touch()\n\n    lib_name = \" \".join(w.capitalize() for w in doc_path.stem.split(\"\
    _\"))\n\n    doc_path.write_text(\n        textwrap.dedent(\n            f\"\"\
    \"\\\n            ---\n            title: {lib_name}\n            documentation_of:\
    \ //complib/{src_file}\n            ---\n        \"\"\"\n        )\n    )\n\n\n\
    if __name__ == \"__main__\":\n    logger: logging.Logger = logging.getLogger(__name__)\n\
    \    handler = colorlog.StreamHandler()\n    formatter = colorlog.ColoredFormatter(\n\
    \        \"%(log_color)s%(asctime)s [%(levelname)s] %(message)s\",\n        datefmt=\"\
    %H:%M:%S\",\n    )\n    handler.setFormatter(formatter)\n    logging.basicConfig(level=logging.INFO,\
    \ handlers=[handler])\n\n    parser = argparse.ArgumentParser(\n        description=\"\
    Generate document files for all libraries.\"\n    )\n    parser.add_argument(\"\
    src\", help=\"Base directory of source files\")\n    parser.add_argument(\"dst\"\
    , help=\"Destination directory\")\n    opts = parser.parse_args()\n\n    src_root\
    \ = Path(opts.src)\n    doc_root = Path(opts.dst)\n\n    for src_file in src_root.glob(\"\
    **/*.hpp\"):\n        generate(src_file.relative_to(src_root))\n"
  dependsOn: []
  isVerificationFile: false
  path: scripts/gendoc.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: scripts/gendoc.py
layout: document
redirect_from:
- /library/scripts/gendoc.py
- /library/scripts/gendoc.py.html
title: scripts/gendoc.py
---

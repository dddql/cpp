config = {
    # Which suffix code file do you want to count?
    # more than as follow, also html, css, clj, lisp, etc.
    'suffix': ('py', 'java', 'c', 'cpp', 'js', 'pde', 'kt', 'dart','html','css'),

    # the comment symbol, which can be judged whether the current line is a comment.
    # However, if the current lines are between the comment symbol
    # and there is not any comment symbol at the beginning of it, it will be misjudged.
    # If the following comment symbol miss any other you want to add, you can do it by yourself
    'comment': ('#', '//', '/*', '/**', '*', ':', ';'),

    # Ignore some directories or files which are not write by yourself,
    # but generate by the projects, just add what you want to add.
    'ignore': ('Others','Games','test_data','.vs','*.out','*.in','*.exe', 'venv', '.git', '.idea', 'build', 'target', 'node_modules','live2d_api','live2dDemo','live2d-widget','FromNetwork','JS Learning Files','.vscode','web.config','.gitignore'),
}

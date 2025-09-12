echo "Enter the matgeo assigment No"
read n

mkdir "matgeo-$n"
cd "matgeo-$n"
mkdir codes
cd codes
touch main.py
touch main.c
cd ..

mkdir figs
mkdir BEAMER
cd BEAMER
touch main_slides.tex

echo "\documentclass{beamer}
\mode<presentation>
\usetheme{Boadilla}

\usepackage{amsmath,amssymb}
\usepackage{graphicx}
\usepackage{siunitx}
\sisetup{per-mode=symbol}
\usepackage{gvv}
\usepackage{listings}
\usepackage{xcolor}

% Code style
\lstset{
  basicstyle=\ttfamily\scriptsize,
  breaklines=true,
  frame=single,
  numbers=left,
  numberstyle=\tiny,
  keywordstyle=\color{blue},
  commentstyle=\color{green!50!black},
  stringstyle=\color{red!60!black},
  showstringspaces=false
}

\title{Matrix 2.6.24}
\author{ai25btech11015 -- M Sai Rithik}
\date{}


\begin{document}
\frame{\titlepage}




%Paste the code here





% CODES

\begin{frame}[fragile]
    \frametitle{C Code}
    \begin{lstlisting}[language=C]
//c code
\end{lstlisting}
\end{frame}
\begin{frame}[fragile]
    \frametitle{C Code}
    \begin{lstlisting}[language=C]
// c code conti
\end{lstlisting}
\end{frame}

\begin{frame}[fragile]
    \frametitle{Python Code}
    \begin{lstlisting}[language=python]
//python code
\end{lstlisting}
\end{frame}

\begin{frame}[fragile]
    \frametitle{Python Code}
    \begin{lstlisting}[language=python]
//python code conti
\end{lstlisting}
\end{frame}



\end{document}
" > main_slides.tex

cd ..
cd ..

cp -r codes_template/codes/msoft/libs "matgeo-$n/codes"

cd ..
cp gvv.sty matgeo-assigment/"matgeo-$n"


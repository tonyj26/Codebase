execute pathogen#infect()
filetype off
syntax on
filetype plugin indent on
set background=dark
colorscheme solarized
set encoding=utf-8
set fileencoding=utf-8
set tabstop=2
set softtabstop=2
set shiftwidth=2
set expandtab
set number
set cursorline
set showmatch
set incsearch
set hlsearch
nnoremap <leader><space> :nohlsearch<CR>
nnoremap j gj
nnoremap k gk

set backspace=indent,eol,start 

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
let g:syntastic_ruby_checkers = ['reek', 'rubylint']
let g:syntastic_python_checkers = ['flake8', 'python']
let Tex_FoldedSections=""
let Tex_FoldedEnvironments=""
let Tex_FoldedMisc=""

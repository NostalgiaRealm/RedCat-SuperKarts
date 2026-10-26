/*
 * COMCTL32.DLL::ImageList_ReplaceIcon at 0041596c
 * int __stdcall ImageList_ReplaceIcon(HIMAGELIST himl, int i, HICON hicon)
 * Address ranges: 0041596c-00415971
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_ReplaceIcon
 */

int __stdcall ImageList_ReplaceIcon(HIMAGELIST himl,int i,HICON hicon)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041596c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ImageList_ReplaceIcon(himl,i,hicon);
  return iVar1;
}


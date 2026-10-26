/*
 * FUN_0044be28 at 0044be28
 * undefined __register FUN_0044be28(int * param_1, LPSIZE param_2)
 * Address ranges: 0044be28-0044be79
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044be28(int *param_1,LPSIZE param_2)

{
  int iVar1;
  HDC hdc;
  char *pcVar2;
  LPSIZE lpsz;
  char local_3c [26];
  char local_22 [26];
  
  pcVar2 = local_3c;
  iVar1 = 0;
  do {
    *pcVar2 = (char)iVar1 + 'A';
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 0x1a);
  iVar1 = 0;
  pcVar2 = local_22;
  do {
    *pcVar2 = (char)iVar1 + 'a';
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar1 != 0x1a);
  iVar1 = 0x34;
  pcVar2 = local_3c;
  lpsz = param_2;
  hdc = (HDC)FUN_00418994(param_1);
  GetTextExtentPointA(hdc,pcVar2,iVar1,lpsz);
  param_2->cx = param_2->cx / 0x34;
  return;
}


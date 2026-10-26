/*
 * FUN_004bfe87 at 004bfe87
 * undefined FUN_004bfe87(void)
 * Address ranges: 004bfe87-004bff24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_004bfe87(char *param_1)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  char *pcVar3;
  void *local_8;
  
  local_8 = (void *)0x0;
  if (DAT_006b674c == 0) {
    cVar1 = *param_1;
    pcVar3 = param_1;
    while (cVar1 != '\0') {
      cVar1 = *pcVar3;
      if (('@' < cVar1) && (cVar1 < '[')) {
        *pcVar3 = cVar1 + ' ';
      }
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  else {
    _Size = FUN_004c345c(DAT_006b674c,0x100,param_1,0xffffffff,0,0,0,1);
    if (((_Size != 0) && (local_8 = _malloc(_Size), local_8 != (void *)0x0)) &&
       (iVar2 = FUN_004c345c(DAT_006b674c,0x100,param_1,0xffffffff,local_8,_Size,0,1), iVar2 != 0))
    {
      FUN_004c51f0(param_1,local_8);
    }
    FUN_004bff99(local_8);
  }
  return param_1;
}


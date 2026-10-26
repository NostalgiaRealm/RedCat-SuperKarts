/*
 * FUN_00439360 at 00439360
 * undefined1 __register FUN_00439360(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00439360-004393f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00439360(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar4;
  int iVar5;
  undefined1 local_5;
  
  local_5 = 0;
  if ((((*(char *)(param_4 + -1) == '\0') &&
       (*(uint *)(param_4 + -8) == (uint)*(ushort *)(param_1 + 0x44))) ||
      ((*(char *)(param_4 + -1) == '\x01' && (*(int *)(param_4 + -8) == *(int *)(param_1 + 0x28)))))
     || ((*(char *)(param_4 + -1) == '\x02' &&
         (*(uint *)(param_4 + -8) == (uint)*(ushort *)(param_1 + 0x54))))) {
    *(int *)(param_4 + -0xc) = param_1;
    local_5 = 1;
  }
  else {
    iVar2 = FUN_00438084(param_1);
    if (-1 < iVar2 + -1) {
      iVar4 = 0;
      do {
        iVar5 = param_4;
        iVar3 = FUN_00438094(param_1,iVar4);
        cVar1 = FUN_00439360(iVar3,extraout_EDX,extraout_ECX,iVar5);
        if (cVar1 != '\0') {
          return 1;
        }
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return local_5;
}


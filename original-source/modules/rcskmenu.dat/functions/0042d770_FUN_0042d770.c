/*
 * FUN_0042d770 at 0042d770
 * undefined __register FUN_0042d770(int param_1, char param_2)
 * Address ranges: 0042d770-0042d815
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d770(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((((*(byte *)(param_1 + 0x2cc) & 8) == 0) && (*(int *)(DAT_0047d770 + 0x38) != 0)) &&
       (*(int *)(*(int *)(DAT_0047d770 + 0x38) + 0x230) != 0)) &&
      (param_1 != *(int *)(DAT_0047d770 + 0x38))) &&
     ((*(char *)(param_1 + 0x217) == '\x01' ||
      (*(char *)(*(int *)(DAT_0047d770 + 0x38) + 0x217) != '\x02')))) {
    iVar2 = 0;
    if ((((*(byte *)(param_1 + 0x20) & 0x10) == 0) && (*(int *)(param_1 + 0x230) != 0)) &&
       ((*(char *)(*(int *)(param_1 + 0x230) + 0x4c) != '\0' ||
        (*(char *)(param_1 + 0x217) == '\x01')))) {
      iVar2 = *(int *)(param_1 + 0x230);
    }
    iVar1 = *(int *)(*(int *)(DAT_0047d770 + 0x38) + 0x230);
    if (param_2 == '\0') {
      FUN_00439fb0(iVar1,iVar2);
    }
    else {
      FUN_00439f94(iVar1,iVar2);
    }
  }
  return;
}


/*
 * FUN_00440624 at 00440624
 * int __register FUN_00440624(int * param_1)
 * Address ranges: 00440624-00440693
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00440624(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0x50))();
  if ((char)iVar2 != '\0') {
    param_1[0x26] = param_1[0xf];
    param_1[0x25] = param_1[0xe];
    return param_1[0xe];
  }
  if (param_1[0x24] != 0) {
    if (((char)param_1[0x23] == '\x02') || ((byte)(*(char *)(param_1[0x24] + 0x4b) - 1U) < 2)) {
      iVar2 = param_1[0xf];
      param_1[0x28] = iVar2;
    }
    else if (((char)param_1[0x23] == '\x01') ||
            (cVar1 = *(char *)(param_1[0x24] + 0x4b),
            iVar2 = CONCAT31((int3)((uint)param_1[0x24] >> 8),cVar1 + -5), (byte)(cVar1 - 3U) < 2))
    {
      iVar2 = param_1[0xe];
      param_1[0x27] = iVar2;
    }
  }
  return iVar2;
}


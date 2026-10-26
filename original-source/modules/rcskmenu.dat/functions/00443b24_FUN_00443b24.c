/*
 * FUN_00443b24 at 00443b24
 * undefined __register FUN_00443b24(int * param_1, int param_2)
 * Address ranges: 00443b24-00443b6b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443b24(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  if (((*(ushort *)(param_1 + 8) & 10) == 0) &&
     (iVar1 = *(int *)(param_2 + 8), (*(byte *)(iVar1 + 0x18) & 1) == 0)) {
    cVar2 = FUN_00440ac4(param_1,(int *)(iVar1 + 0x10),(int *)(iVar1 + 0x14));
    if (cVar2 == '\0') {
      *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 1;
    }
  }
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  return;
}


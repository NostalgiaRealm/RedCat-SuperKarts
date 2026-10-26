/*
 * FUN_0046e2d4 at 0046e2d4
 * undefined __register FUN_0046e2d4(int param_1, undefined4 * param_2)
 * Address ranges: 0046e2d4-0046e328
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e2d4(int param_1,undefined4 *param_2)

{
  MCIERROR MVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 auStack_20 [4];
  undefined4 local_1c [4];
  
  if ((*(char *)(param_1 + 0x2c9) != '\0') && (*(char *)(param_1 + 0x2cf) != '\0')) {
    *(undefined4 *)(param_1 + 0x2d0) = 0x40000;
    MVar1 = mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x843,0x40000,(DWORD_PTR)auStack_20);
    *(MCIERROR *)(param_1 + 0x2ec) = MVar1;
    puVar3 = local_1c;
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


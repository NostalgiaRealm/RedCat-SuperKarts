/*
 * FUN_0046e230 at 0046e230
 * undefined __register FUN_0046e230(int param_1, undefined4 * param_2)
 * Address ranges: 0046e230-0046e2d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e230(int param_1,undefined4 *param_2)

{
  MCIERROR MVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  int local_40 [4];
  undefined1 local_30 [4];
  undefined4 local_2c [4];
  undefined4 local_1c [4];
  
  bVar6 = 0;
  piVar3 = local_40;
  for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = *param_2;
    param_2 = param_2 + 1;
    piVar3 = piVar3 + 1;
  }
  if ((*(char *)(param_1 + 0x2c9) != '\0') && (*(char *)(param_1 + 0x2cf) != '\0')) {
    if ((local_40[3] == 0) && (local_40[2] == 0)) {
      FUN_0040ebe8(local_40[0],local_40[1],*(undefined4 *)(param_1 + 0x2f8),local_1c,
                   *(undefined4 *)(param_1 + 0x2fc));
    }
    else {
      piVar3 = local_40;
      puVar4 = local_1c;
      for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    *(undefined4 *)(param_1 + 0x2d0) = 0x50000;
    puVar4 = local_1c;
    puVar5 = local_2c;
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
      puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
    }
    MVar1 = mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x842,0x50000,(DWORD_PTR)local_30);
    *(MCIERROR *)(param_1 + 0x2ec) = MVar1;
  }
  return;
}


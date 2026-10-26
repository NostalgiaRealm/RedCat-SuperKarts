/*
 * FUN_00471bc0 at 00471bc0
 * undefined __register FUN_00471bc0(int * param_1)
 * Address ranges: 00471bc0-00471c6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471bc0(int *param_1)

{
  char cVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x03') {
    FUN_00472cfc((int)param_1);
    FUN_00472fe0();
  }
  FUN_00471c70((int)param_1,param_1[0xce]);
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x03') {
    if ((char)param_1[0xcf] == '\x01') {
      FUN_00473158();
      *(undefined1 *)(param_1 + 0xb5) = 8;
    }
    else {
      *(undefined1 *)(param_1 + 0xb5) = 9;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xb5) = 4;
  }
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x03') {
    FUN_00457b34(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
    iVar2 = extraout_ECX;
    uVar3 = extraout_EDX;
  }
  else {
    FUN_00457918();
    iVar2 = extraout_ECX_00;
    uVar3 = extraout_EDX_00;
  }
  FUN_0042eb18(param_1,uVar3,iVar2);
  return;
}


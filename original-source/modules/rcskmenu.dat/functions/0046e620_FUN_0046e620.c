/*
 * FUN_0046e620 at 0046e620
 * undefined __register FUN_0046e620(int param_1, int * param_2)
 * Address ranges: 0046e620-0046e66f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e620(int param_1,int *param_2)

{
  BOOL BVar1;
  uint uVar2;
  int local_1008 [1024];
  
  local_1008[0] = param_1;
  BVar1 = mciGetErrorStringA(*(MCIERROR *)(param_1 + 0x2ec),(LPSTR)local_1008,0x1000);
  if (BVar1 == 0) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c878,param_2);
  }
  else {
    uVar2 = FUN_00408340((char *)local_1008);
    FUN_00403c38(param_2,local_1008,uVar2);
  }
  return;
}


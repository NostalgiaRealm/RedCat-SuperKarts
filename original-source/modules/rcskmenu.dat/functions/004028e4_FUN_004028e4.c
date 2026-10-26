/*
 * FUN_004028e4 at 004028e4
 * undefined __register FUN_004028e4(int param_1, int * param_2)
 * Address ranges: 004028e4-0040293a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004028e4(int param_1,int *param_2)

{
  DWORD DVar1;
  byte *pbVar2;
  CHAR local_114 [264];
  
  if (param_1 == 0) {
    DVar1 = GetModuleFileNameA((HMODULE)0x0,local_114,0x105);
    FUN_00403c38(param_2,(undefined4 *)local_114,DVar1);
  }
  else {
    pbVar2 = (byte *)GetCommandLineA();
    while( true ) {
      pbVar2 = FUN_0040286c(pbVar2,param_2);
      if ((param_1 == 0) || (*param_2 == 0)) break;
      param_1 = param_1 + -1;
    }
  }
  return;
}


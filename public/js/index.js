function saveFile() {
  const dS = document.getElementById('ds-name');
  console.log(dS.textContent);
  const dim = document.getElementById('dimensions');
  const dimA = document.getElementById('size');
  const lb = document.getElementById('lBound');
  const rb = document.getElementById('rBound');
  const data = { 
    ds: dS.textContent,
    dimensions : dim.value,
    size : dimA.value,
    lBound : lb.value,
    rBound : rb.value
  };

  async function orderRun() {
    console.log("fetching")
    const res = await fetch("/submit-form", {
      method: "POST",
      body: JSON.stringify(data),
      headers: {
        "Content-Type": "application/json",
      },
    });

    window.open('/send-file'); //does the download
  }

  orderRun();
}
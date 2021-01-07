using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public int finishCheck = 2;
    public bool isFinish = false;

    private float fOrigSpeed = 100.0f;
    public float fSpeed = 100.0f;
    public float fRot = 100.0f;

    private Rigidbody rigidbody = null;
    void Start()
    {
        fOrigSpeed = fSpeed;

        rigidbody = this.gameObject.GetComponent<Rigidbody>();
    }

    public float Labtime = 0.0f;
    private bool check = false;

    private float preBoostTime = 1.0f;
    private float boostTime = 1.0f;

    private float canBoostTime = 0.0f;
    private float goalBoostTime = 5.0f;

    private bool isHit = false;
    private bool isBoost = false;
    private bool isBossting = false;

    void Update()
    {
        if (Labtime >= 0.5f)
        {
            if (canBoostTime >= goalBoostTime)
                isBoost = true;

            if (isFinish)
            {
                ReduceSpeed();
            }

            if (IsSpeedNotZero())
            {
                if (isBoost && Input.GetKey(KeyCode.Space))
                {
                    isBossting = true;
                    fSpeed = 150;
                }
                else if (isBossting)
                    boostTime -= Time.deltaTime;

                if (boostTime <= 0)
                {
                    isBossting = false;
                    fSpeed = fOrigSpeed;
                    isBoost = false;
                    boostTime = preBoostTime;

                    goalBoostTime = canBoostTime + 5.0f;
                }

                float moveDelta = fSpeed * Time.deltaTime;

                if (Input.GetKey(KeyCode.W))
                    this.transform.Translate(Vector3.forward * moveDelta);
                else if (Input.GetKey(KeyCode.S))
                    this.transform.Translate(Vector3.back * moveDelta);

                if (Input.GetKey(KeyCode.A))
                    this.transform.rotation *= Quaternion.AngleAxis(moveDelta * -1, Vector3.up);
                else if (Input.GetKey(KeyCode.D))
                    this.transform.Rotate(Vector3.up * moveDelta);
            }
            else
            {
                if (!check)
                {
                    check = true;
                    GameManager.Instance.LabTimeRecord(Labtime);
                }
            }
        }

        Labtime += Time.deltaTime;
        canBoostTime += Time.deltaTime;
    }

    private void OnGUI()
    {
        Vector3 camPos = new Vector3(Camera.main.pixelWidth / 2, Camera.main.pixelHeight / 2);

        if (isBoost && !isBossting)
        {
            GUI.Box(new Rect(camPos.x, camPos.y, 100, 30), "Boost");
        }
        else if (isBoost && isBossting)
        {
            GUI.Box(new Rect(camPos.x, camPos.y, 100, 30), "- Boosting -");
        }
    }

    private void ReduceSpeed()
    {
        if (fSpeed > 0)
            fSpeed -= 0.1f;
    }

    private void OnCollisionEnter(UnityEngine.Collision collision)
    {
        if (rigidbody == null)
            return;
        GameObject hitObj = collision.gameObject;

        if (hitObj.tag == "Floor")
            return;

        // if (hitObj.tag == "Vehicle" && !isFinish)
        if (!isFinish)
        {
            isHit = true;
            goalBoostTime = canBoostTime + 5.0f;

            float tempSpeed = fSpeed;
            fSpeed = tempSpeed * 0.5f;
        }
        // else if (hitObj.tag == "Vehicle" && isFinish)
        else if (isFinish)
        {
            fSpeed = 0.0f;
        }
    }

    private void OnCollisionStay(UnityEngine.Collision collision)
    {
        //if (rigidbody == null)
        //    return;

        //GameObject hitObj = collision.gameObject;

        //if (hitObj.tag == "Floor")
        //    return;

        //// if (hitObj.tag == "Vehicle" && !isFinish)
        //if (!isFinish)
        //{
        //    float tempSpeed = fSpeed;
        //    fSpeed = tempSpeed * 0.5f;
        //}
        //// else if (hitObj.tag == "Vehicle" && isFinish)
        //else if (isFinish)
        //{
        //    Debug.Log("hit");
        //    fSpeed = 0.0f;
        //}
    }

    private void OnCollisionExit(UnityEngine.Collision collision)
    {
        if (rigidbody == null)
            return;

        GameObject hitObj = collision.gameObject;

        if (hitObj.tag == "Floor")
            return;

        if (!isFinish)
        {
            isHit = false;
            fSpeed = fOrigSpeed;
        }
    }


    private void OnTriggerEnter(Collider other)
    {
        if (rigidbody == null)
            return;
    }

    private void OnTriggerExit(Collider other)
    {
        if (rigidbody == null)
            return;

        GameObject hitObj = other.gameObject;

        if (hitObj.tag == "EndLine")
        {
            finishCheck--;

            if (finishCheck <= 0)
                isFinish = true;
        }
    }

    private bool IsSpeedNotZero()
    {
        if (fSpeed > 0)
            return true;
        else
        {
            // rigidbody.isKinematic = true;
            return false;
        }
    }
}
